
// ptm:u functions not available in ctrulib.

#ifdef __cplusplus
extern "C" {
#endif

Result ptmuxInit(void);

void ptmuxExit(void);

Result PTMUX_GetAdapterState(u8 *out);

Result mcuInit(void);
Result mcuExit(void);
Result mcuGetBatteryLevel(u8* out);

#ifdef __cplusplus
}
#endif
