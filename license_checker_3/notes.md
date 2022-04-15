# Solution write up

## Steps
1. Import into Ghidra
2. Find the main function Symbol Tree `->` main.
3. Edit the Function Signature for the main function to `void main(int argc, **char argv)`
4. Start renaming variables, alternatively if the program is small (like in this instance), copy over the code into a new `.c` file so we can utilize `printf` to debug.

### Code starting point
```c
void main(int argc,char **argv)

{
  int iVar1;
  size_t sVar2;
  long in_FS_OFFSET;
  char local_19;
  int local_18;
  int local_14;
  undefined8 local_10;
  
  local_10 = *(undefined8 *)(in_FS_OFFSET + 0x28);
  if (argc != 2) {
    printf("Usage : %s <license pass code here [numbers only]>\n",*argv);
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  local_18 = 0;
  local_14 = 0;
  while( true ) {
    sVar2 = strlen(argv[1]);
    if ((int)sVar2 <= local_14) break;
    local_19 = argv[1][local_14];
    iVar1 = atoi(&local_19);
    local_18 = local_18 + iVar1;
    local_14 = local_14 + 1;
  }
  if (local_18 == 0x32) {
    puts("Premium access has been activated !");
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  puts("Wrong license code");
                    /* WARNING: Subroutine does not return */
  exit(0);
}
```

### Code final
see `reversed.c`

### Tips
Compile using `gcc`. `gcc reversed.c -o reversed`
