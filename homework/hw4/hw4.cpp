#include "hw4.h"
/*
  SR Kanna
  CS162
  Program 4
  3/5/2014

  Purpose: This is where I'm declaring my functions
*/

//This is the constructor to initialize all values
housing::housing(const char filename[])
{
  strcpy(m_filename,filename);
  low = 0;						//initialize to zero
  high = 0;						//initialize to zero
  temp[0] = '\0';						//initialize to null
  temp2[0] = '\0';					//initialize to null
  temp3[0] = '\0';

  for (int i = 0; i < 4; ++i){				//initialze pointers to null
    list[i].location = NULL;			//4 - number of houses in the external file
    list[i].feature1 = NULL;
    list[i].feature2 = NULL;
    list[i].feature3 = NULL;
  }
}

//This is the destuctor function
housing::~housing()
{
  for (int i = 0; i < 4; ++i)
    {
      if (list[i].location){
        delete [] list[i].location;		//delete 
        delete [] list[i].feature1;
        delete [] list[i].feature2;
        delete [] list[i].feature3;
      }
    }
}

//This function is reading everything into an array of struct
void housing::read_in(void)
{
  int i = 0;
  ifstream file_in;
  file_in.open(m_filename);					//say which file
  if(!file_in)
    return;
  else
    {
      while(!file_in.eof() && i < 4)				//while there's still info and it's less than the number of lines
        {
          file_in >> list[i].price;
          file_in.ignore(100,'|');				//deliminer is tab
		
          file_in >> list[i].size;
          file_in.ignore(100,'|');
		
          file_in >> list[i].bedroom;
          file_in.ignore(100,'|');

          file_in.get(temp,400,'|');				//dynamically allocating memory
          file_in.ignore(100,'|');
          list[i].location = new char[strlen(temp)+1];		//sizes the array of struct
          strcpy(list[i].location, temp);				//copies user info into correctly sized array of struct
		
          file_in.get(temp,400,'|');
          file_in.ignore(100,'|');
          list[i].feature1 = new char[strlen(temp)+1];
          strcpy(list[i].feature1,temp);
	   		
          file_in.get(temp,400, '|');
          file_in.ignore(100,'|');
          list[i].feature2 = new char[strlen(temp)+1];
          strcpy(list[i].feature2,temp);
		
          file_in.get(temp,400, '\n');
          file_in.ignore(100,'\n');
          list[i].feature3 = new char[strlen(temp)+1];
          strcpy(list[i].feature3,temp);
		
          ++i;	
        }
    }
}

//Figuring out what the user wants
void housing::prioritize(int selection)									//argument passed in from int main
{
  switch (selection){
  case 1:												//selection variable applies throughout switch statement
    cout << "Please enter your lower price range. ";
    cin >> low;										//pulled from private class
    cin.ignore(100,'\n');
    cout << "Please enter your higher price range. ";
    cin >> high;										//pulled from private class
    cin.ignore(100,'\n');
	
    for (int k = 0; k < 4; ++k)
      {
        if(list[k].price >= low && list[k].price <= high)				//checks if there is a value between low and high value
          cout << "The following housing options are a match: " << k << endl;	//outputs i as the name of the housing option
      }

    break;
  case 2:
    cout << "Please enter your lowest size range. ";
    cin >> low;
    cin.ignore(100,'\n');
    cout << "Please enter your largest size preferanc. ";
    cin >> high;
    cin.ignore(100,'\n'); 
		
    for (int k = 0; k < 4; ++k)
      {
        if(list[k].size >= low && list[k].size <= high)
          cout << "The following housing options are a match: " << k << endl;
      }

    break;
  case 3:
    cout << "Please enter you lowest number of bedrooms. ";
    cin >> low;
    cin.ignore(100,'\n');
    cout << "Please enter you largest number of bedrooms. ";
    cin >> high;
    cin.ignore(100,'\n');
		
    for (int k = 0; k <4; ++k)
      {
        if(list[k].bedroom >= low && list[k].bedroom <= high)
          cout << "The following housing options are a match: " << k << endl;
      }
    break;
  case 4:
    char * location;												//local pointer
    cout << "Please enter your prefered location: ";
    cin.get(temp,400,'\n');												//accessing private
    cin.ignore(100,'\n');
    location = new char[strlen(temp)+1];										//dynamically allocated
    strcpy(location,temp);
		
    for (int k = 0; k < 4; ++k)											//checks
      {
        if(strcmp(list[k].location,location)==0)
          cout << "The following housing options are a match: " << k << endl;
      }
    break;
  case 5:
    char * feature1;
    char * feature2;
    char * feature3;
		
    cout << "Please enter your first extra feature: ";
    cin.get(temp,400,'\n');
    cin.ignore(100,'\n');
		
    cout << "Please enter your second extra feature: ";								//feature 2
    cin.get(temp2,400,'\n');
    cin.ignore(100,'\n');
		
    cout << "Please enter your third extra feature: ";								//feature 3
    cin.get(temp3,400,'\n');
    cin.ignore(100,'\n');

    feature1 = new char[strlen(temp)+1];										//dynamically allocating
    strcpy(feature1,temp);
    feature2 = new char[strlen(temp2)+1];
    strcpy(feature2,temp2);
    feature3 = new char[strlen(temp3)+1];
    strcpy(feature3,temp3);

    for (int k =0; k < 4; ++k)
      {
        if(strcmp(list[k].feature1,feature1)==0 || strcmp(list[k].feature1,feature2)==0 || strcmp(list[k].feature1,feature3)== 0 ||
	strcmp(list[k].feature2,feature2)==0 || strcmp(list[k].feature2,feature2)==0 || strcmp(list[k].feature2,feature3)==0 ||
	strcmp(list[k].feature3,feature1)==0 || strcmp(list[k].feature3,feature2)==0 || strcmp(list[k].feature3,feature3) == 0)
          cout << "The following housing options are a match based on any of your required features: " << k << endl;
      }

    delete [] feature1;												//deleting
    delete [] feature2;
    delete [] feature3;
    break;
  }
}

//display the entire structure
void housing::display_all()
{
  int i = 0;
  while (i<4)
    {
      cout << i << '\t';												//display all using tabs
      cout << list[i].price << '\t';
      cout << list[i].size << '\t';
      cout << list[i].bedroom << '\t';
      cout << list[i].location << '\t';
      cout << list[i].feature1 << '\t';
      cout << list[i].feature2 << '\t';
      cout << list[i].feature3 << '\n';										//end w/new line to indicate new housing
      ++i;
    }
}
