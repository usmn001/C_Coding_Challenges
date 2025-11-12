/*
 ============================================================================
 Name        : P1.c
 Author      : M USMAN
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style 
 Problem Solved : https://www.testdome.com/tests/embedded-systems-c-online-test/155 ( Watched_Videos)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Video {
    char *name;
    int unique_views;
} Video;

typedef struct Viewer {
    char *username;
    Video *watched_videos;
    int watched_videos_size;
} Viewer;

int count_views(Viewer **viewers, int viewers_size, char *video_name)
{
    // Waiting to be implemented

	int cnt=0;

	/*  Debug Statements
	printf("Double Pointer viewers address : %p \n",viewers);
	printf("Pointer pt1 Contains Address : %p \n ",pt1);
    printf("%i",sizeof(*viewers));
    printf("%s",viewers[1]->username);
    printf("%s \n ",viewers[0]->watched_videos[0].name);
    printf("%s \n ",viewers[0]->watched_videos[1].name);
    */

	for(int index1=0;index1<viewers_size;index1++)
	{
      for(int index2=0;index2<viewers[index1]->watched_videos_size;index2++)
      {
    	  if( (strcmp ( (viewers[index1]->watched_videos[index2].name),(video_name) ))==0 )
    	  {
    		  cnt +=1;
    	  }
      }

	}

    return cnt;
}


int main()
{
    Video videos[] = { {.name = "Soccer", .unique_views = 500},
                       {.name = "Basketball", .unique_views = 1000} };

    Viewer viewer1 = {.username = "Dave", .watched_videos = videos,
                     .watched_videos_size = 2};

    Viewer viewer2 = {.username = "Usman", .watched_videos = videos,
                        .watched_videos_size = 2};

    Viewer *viewers[] = { &viewer1,&viewer2 };

    /* Debug Statements

    printf("%s \n",viewer1.watched_videos[1].name);
    viewer1.watched_videos[1].name;
    printf("Viewers Array Pointer Has Address %p \n",viewers);
    printf("Viewers Array 1st Element Address %p \n",viewers[0]);
    printf("Viewers Array 2nd Element Address %p \n",viewers[1]);
    printf("Viewer Element Address %p \n",&viewer);

    */

    count_views(viewers,2,"Soccer");
    printf("%d", count_views(viewers, 2, "Soccer")); /* should print 1 */
    return 0;
}

