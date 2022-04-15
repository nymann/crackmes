#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
        char clear_text[] = "This is an example text with only one line.\n";
        int len = strlen(clear_text);
        char encrypted_text[len];
        srand(0xdeadbeef);
        int seeded_value = rand();
        
        // encrypting
        for(int i = 0; i< len; i++) {
                encrypted_text[i] = (char)(clear_text[i] ^ (int) (seeded_value % 0xff));
                printf("%c", encrypted_text[i]);
        }

        // Decrypting
        for(int n = 0; n< len; n++) {
                int t = (int) encrypted_text[n] ^ (int) (seeded_value % 0xff);
                printf("%c", t);
        }

        return 0;
}
