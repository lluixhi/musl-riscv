__asm__(
".text\n"
".global " START "\n"
".type " START ",%function\n"
START ":\n\t"
".weak _gp\n"
".hidden _gp\n\t"
".long _gp\n\t"
"la gp, _gp\n\t"
"mv a0, sp\n\t"
"jal 1f\n"
".weak _DYNAMIC\n"
".hidden _DYNAMIC\n\t"
".long _DYNAMIC\n"
"1:\tla a1, _DYNAMIC\n\t"
"add a1, a1, ra\n\t"
"addi sp, sp, -16\n\t"
"jal " START "_c"
);
