#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>
#include "gestionnaire.h"




void execute_command(int argc, char** argv){




    time_t begin;

    time_t end;

    int opt;

    int index = 0;

    char* path = NULL;

    int nb_iterations = 0;

    int delais = 0;

    char** commande = (char**)malloc(sizeof(char*)*argc);


    while((opt = getopt(argc, argv, "hp:i:d:c:")) != -1){
        switch(opt){

            case 'h':
                printf("-p : pour spécifier le path de la commande a éxecuter. \n");

                printf("-i : pour spécifier le nombre d'itérations. \n");

                printf("-d : pour spécifier le temps en secondes entre chaques commandes.\n");

                printf("-c : pour spécifier la commande à exécuter.\n");

                printf("! si la commande nécessite des flags particuliers, utiliser le flag -c pour les passer en paramètre.");

                break;

            case 'p':

                path = optarg;
                break;

            case 'i':
                nb_iterations = atoi(optarg);

                break;

            case 'd':
                delais = atoi(optarg);
                break;

            case 'c':

                commande[index] = (char*)malloc(sizeof(char)*strlen(optarg));
                
                commande[index] = optarg;
                index++;
                break;


            default:
                abort();

        }

    }

    commande[index] = NULL;

    for(int i =0; i<= index;i++){
        printf("%s", commande[i]);
    }



    for(int i=0; i< nb_iterations; i++){


        begin = time(NULL);

        pid_t valuefork = fork();

        if(valuefork == 0){    
            
            
            if(execv(path, commande) == -1){
                printf("error");
            }


        } 

        
        wait(NULL);

        end = time(NULL);

        int timespend = (int) difftime(end, begin); 

        int sleeptime = delais - timespend;

        if(sleeptime >= 0){ //verifie que le sleep est une valeur positive.
            sleep(delais-timespend);
        }
        printf("%d\n", sleeptime);
    }

}