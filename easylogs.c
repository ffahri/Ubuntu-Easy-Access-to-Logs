#include <stdio.h>
#include <stdlib.h>
void ufwlog(void);
void authlog(void);
void maillog(void);
void freemem(void);
int main()
{
	void (*f[4])(void) = {ufwlog,authlog,maillog,freemem,uptime};
	int choose=0;
	while(choose!=-1)
	{

		printf("\e[1;31m1.Show last 10 lines on ufw.log (/var/log/ufw.log)\n\e[1;32m2.Show last 10 lines on auth.log(/var/log/auth.log)\n");
		printf("\e[1;36m3.Show last 10 lines on mail.log (/var/log/mail.log)\n\e[1;37m4.Free memory (/proc/sys/vm/drop_caches)*YOU HAVE TO OPEN WITH SUDO*\n");
		printf("\e[0;0mChoose and write number. For exit : -1\n");
		scanf("%d",&choose);
		if(choose>-1 && choose<5)
		(*f[choose-1])();

	}
}
void ufwlog(void)
{	
	system("tail /var/log/ufw.log");
}
void authlog(void)
{
	system("tail /var/log/auth.log");
}
void maillog(void)
{
	system("tail /var/log/mail.log");
}
void freemem(void)
{
	printf("Current use\n");
	system("free -h");
	printf("*************************************************\n");
	system("echo 3 > /proc/sys/vm/drop_caches");
	system("free -h");
}
void uptime(void)
{
	system("uptime");
}
