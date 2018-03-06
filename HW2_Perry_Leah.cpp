#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

long total = 0;

void *Counter(void *beginning);
const int threadNum = 4;
int main(){
  pthread_t tid[threadNum];//thread id for 4 threads
  int count; //thread number
  int array[4] = {0, 250000, 500000, 750000};
  //make threads
  for(count = 0; count < threadNum; count++){
  
    if(pthread_create(&tid[count], NULL, Counter, (void *)&array[count]) == -1){
	cout << "Thread error" << endl;
	exit(-1);
    }//end if for thread creation
    }//end for loop

    //wait for thread completion
    for(count = 0; count < threadNum; count++){
      if(pthread_join(tid[count], NULL) == -1){
         cout << "pthread_join error" << endl;
         exit(-1);
  }//end if
}//end for
    cout << "All of the numbers 1 to 1 million add up to " << total << endl;
 return 0;
}//end main

void *Counter(void *beginning){
  int start =*(int*)beginning;
  cout << "Counting from " << start << " to " << start+250000 << endl;
  for(int i = start; i <= start+250000; i++){
    total = total + i;
  }//end for

  return NULL;
}//end Counter
