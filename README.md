# sleepmask_ekko_cfg
Code snippets to add on top of cobalt strike sleepmask kit so that ekko can work in a CFG protected process.

All credits to [@Icebreaker](https://github.com/IcebreakerSecurity)

## Usage
1. Enable ekko sleep in sleepmask kit
2. Include cfg.c
3. Add below codes before ekko sleep
```
   PVOID NtContinue = KERNEL32$GetProcAddress(KERNEL32$GetModuleHandleA("ntdll.dll"),"NtContinue");
   //PVOID NtContinue = NTDLL$NtContinue; //<-- this should be the same as above
   if (!markCFGValid_nt(NtContinue))
    {
        return;
    }
```
4. Put cfg.c in folder
5. Append the contents in bofdefs.h
6. Compile

## Caveat
1. Sleep 0 will terminate the process, meaning that socks cannot be used (However, if interactive process is needed, its pointless to use ekko, just revert back to use original sleep)

## Reference
1. https://github.com/IcebreakerSecurity/Ekko_CFG_Bypass
