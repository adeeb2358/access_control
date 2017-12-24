#include "commonHeader.h"
#include "functions.h"


void getUserDetails(){
	struct passwd *user_details;

	while((user_details = getpwent()) != NULL){
		if(user_details->pw_uid >= 1000){
			printf("%s\n",user_details->pw_name);
		}
	}

	return;
}

void real_effect_uid(){
	printf("Real UserID = %d\n",getuid());
	printf("Effective UserID = %d\n",geteuid());	

	/*
		check whether if we can open /etc/hosts for writing
	*/
	printf("open: %d\n",open("/etc/hosts",O_RDWR));

	/*
		access tests what the real user can do on a file
	*/
	printf("access:%d\n",access("/etc/hosts/",W_OK));

	/*
		now drop our root previlege and try again
	*/

	seteuid(getuid());
	printf("Real UserID = %d\n",getuid());
	printf("Effective UserID = %d\n",geteuid());	

		/*
		check whether if we can open /etc/hosts for writing
	*/
	printf("open: %d\n",open("/etc/hosts",O_RDWR));

	/*
		access tests what the real user can do on a file
	*/
	printf("access:%d\n",access("/etc/hosts/",W_OK));
	return;
}