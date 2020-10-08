#include "musicplayer.hpp"



void Player::playbackWatchdog(void* infoIn)
{
	struct watchdogInfo* info = infoIn;

	while(runThreads)
	{
		svcWaitSynchronization(*info->errInfo->failEvent, U64_MAX);
		svcClearEvent(*info->errInfo->failEvent);

		if(*info->errInfo->error > 0)
		{
			consoleSelect(info->screen);
			printf("Error %d: %s", *info->errInfo->error,
					ctrmus_strerror(*info->errInfo->error));

			if(info->errInfo->errstr != NULL)
			{
				printf(" %s", info->errInfo->errstr);
				delete(info->errInfo->errstr);
			}

			printf("\n");
		}
		else if (*info->errInfo->error == -1)
		{
			/* Used to signify that playback has stopped.
			 * Not technically an error.
			 */
			consoleSelect(info->screen);
			puts("Stopped");
		}
	}

	return;
}

/**
 * Stop the currently playing file (if there is one) and play another file.
 *
 * \param	ep_file			File to play.
 * \param	playbackInfo	Information that the playback thread requires to
 *							play file.
 */
static int Player::changeFile(const char* ep_file, struct playbackInfo_t* playbackInfo)
{
	s32 prio;
	static Thread thread = NULL;

	if(ep_file != NULL && getFileType(ep_file) == FILE_TYPE_ERROR)
	{
		*playbackInfo->errInfo->error = errno;
		svcSignalEvent(*playbackInfo->errInfo->failEvent);
		return -1;
	}

	/**
	 * If music is playing, stop it. Only one playback thread should be playing
	 * at any time.
	 */
	if(thread != NULL)
	{
		/* Tell the thread to stop playback before we join it */
		stopPlayback();

		threadJoin(thread, U64_MAX);
		threadFree(thread);
		thread = NULL;
	}

	if(ep_file == NULL || playbackInfo == NULL)
		return 0;

	playbackInfo->file = strdup(ep_file);
	printf("Playing: %s\n", playbackInfo->file);

	svcGetThreadPriority(&prio, CUR_THREAD_HANDLE);
	thread = threadCreate(playFile, playbackInfo, 32 * 1024, prio - 1, -2, false);

	return 0;
}

Player::PlaySong(){
    Player::changeFile("sdmc:/3ds/NPI/music/Test/Faint.mp3", &playbackInfo_t);
}