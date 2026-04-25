.intel_syntax noprefix
.global Sum

Sum:
    lea eax, [esi + edi]
    ret
