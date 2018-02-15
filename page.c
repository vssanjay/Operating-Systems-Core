#include<stdio.h>
#include<unistd.h>
#include<string.h>


int main(int argc, char* argv[])
	{
		if( argc!= 4)
		{
			printf("  The Usage should be : ProgramName AlgorithmToUse ReferenceStringFile NumberOfFrames \n");
		}

		else
		{
			char algorithmToUse[10];
			FILE *file;
			int frameSize;
			int pageFault =0;
			int sizeOfReference;
			int length;
			strcpy(algorithmToUse, argv[1]);
			int c =0;
			
			char fileContent[100];
			
			while (c<strlen(algorithmToUse))
			{
				algorithmToUse[c] = toupper(algorithmToUse[c]);
				c++;
			}
			printf("\nThe algorithm that you chose is : %s \n", algorithmToUse);


			if(strcmp(algorithmToUse,"FIFO") !=0  && strcmp(algorithmToUse,"LRU") !=0 )
			{
				printf("\n You have given the wrong algortihm Input \n");

			}

			else
			
			{	
						
				FILE *file;
				int i;
				int j=0;
				char tempConvert;
				int stringValues[100];
				char fileContent[100];
				file = fopen(argv[2], "r");
				

				
				fseek(file, 0L, SEEK_END);
				length = ftell(file);
				fseek(file, 0L, SEEK_SET);

				   /* Read and display data */
				
				fread(fileContent, length, 1, file);

				//fscanf(file, "%d", &stringValues);
				//fflush(stdout);
				
				
				
				for(i=0; i<=length; i++)
				{	// was to try to try and convert the entire string into integer using Atoi but, it needs an array?
					//if(isspace(fileContent[i]) == 0)
					//{	
						if(isspace(fileContent[i]) ==0)
						{
							if(fileContent[i]>='0' && fileContent[i]<='9')
								{
								stringValues[j]=fileContent[i] - '0';
								j++;
								}
							
								
						}

					//}
					//else
					//{
					//	i++;
					//}
					
						

				}
				i = 0 ;
				printf("The Given String input from the file is : ");
				while(i<j)
				{
					printf("%d,\t", stringValues[i]);
					i++;
				}
				fclose(file);
				frameSize = atoi(argv[3]);

				if((frameSize <= 1) || (frameSize >= 7))
				{
					printf("\n The number of frames You have entered is too high or low, try in between 1 & 7 \n");
					return(1);
				}

				else
				{


				int m, n, s, a, b, k, l, position, pages;
				int temporary[frameSize], temp[frameSize], temp2[frameSize];

				//algorithm LRU or FIFO to execute
				//FIFO
				//______________________________________________//
				
				if(strcmp(algorithmToUse,"FIFO") ==0 )
				{
			
						printf("\nEnter Total Number of Pages:\t");
      					scanf("%d", &pages);
						for(m=0; m<= frameSize; m++)
						{
							temp[m]= -1;
						}

						for(m=0; m<= pages; m++)
						{
							s=0;
							for(n=0; n<frameSize; n++)
							{
								if(stringValues[m]==temp[n])
								{
									s++;
									pageFault --;

								}
							}
							pageFault ++;
							if((pageFault <= frameSize) && (s==0))
							{
								temp[m]= stringValues[m];
							}
							else if(s==0)
							{
								temp[(pageFault - 1) % frameSize] = stringValues[m];
							}

							printf("\n");
							for(n=0; n<frameSize; n++)
							{
								printf("%d\t", temp[n]);
							}


						}
				printf("\n Total Page faults in FIFO is	: %d\n", pageFault);
				return 0;
				}
				//LRU
				//_______________________________________________________________________


				else if( (strcmp(algorithmToUse,"LRU") ==0 ))
				{
						printf("\nEnter Total Number of Pages:\t");
      					scanf("%d", &pages);
						for(m=0; m<= frameSize; m++)
						{
							temp2[m]= -1;
						}

						for(n = 0; n < pages; n++)
						{
							a = 0, b = 0;
							for(m = 0; m < frameSize; m++)
							{
								if(temp2[m] == stringValues[n])
								{
									a = 1;
									b = 1;
									break;
								}
							}
							if(a == 0)
							{
								for(m = 0; m < frameSize; m++)
								{
									if(temp2[m] == -1)
									{
										temp2[m] = stringValues[n];
										b = 1;
										break;
									}
								}
							}
							if(b == 0)
							{
								for(m = 0; m < frameSize; m++)
								{
									temporary[m] = 0;
								}
								for(k = n - 1, l = 1; l <= frameSize - 1; l++, k--)
								{
									for(m = 0; m < frameSize; m++)
									{
										if(temp2[m] == stringValues[k])
										{
											temporary[m] = 1;
										}
									}
								}
								for(m = 0; m < frameSize; m++)
								{
									if(temporary[m] == 0)
									position = m;
								}
								temp2[position] = stringValues[n];
								pageFault++;
							}
							printf("\n");
							for(m = 0; m < frameSize; m++)
							{
								printf("%d\t", temp2[m]);
							}
						}
				
				printf("\nTotal Number of Page Faults in LRU is :\t%d\n", pageFault);
				return 0;
				}
				
				else 

					{
					printf("Wrong ALg");
					}
				}

			}
		}
}
		
	