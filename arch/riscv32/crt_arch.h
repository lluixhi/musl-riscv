__asm__(
".text\n"
".global " START "\n"
".type " START ",%function\n"
START ":\n"
".weak _gp\n"
".hidden _gp\n\t"
"lla gp, _gp\n\t"
"mv a0, sp\n"
".weak _DYNAMIC\n"
".hidden _DYNAMIC\n\t"
"lw a1, _DYNAMIC\n\t"
"addi sp, sp, -16\n\t"
"jal " START "_c"
);
