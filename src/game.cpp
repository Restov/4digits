#ifndef GAME
#define GAME

#include "sequence.cpp"

using namespace std;

class Game
{
public:
	Game(){
		sec = new Sequence;
		turns = 0;
	}

	~Game(){
		delete sec;
	}

	void join(){
		bool flag = false;
		int lenght = 4;
		char *input = new char[lenght];
		
		string str;
		while(!flag){
			cout << "введите " << lenght << " числа от 0 до 9 " << endl;
    		cin >> str;
    		for(int i = 0 ; i < lenght ; ++i){
    			input[i] = str[i];
			}
    		//cout << input <<endl;
    		if(is_valid(input , lenght)){
    			 sec->check(input , lenght);
    		}
    		else {
    			cout << "некорректный ввод" << endl;
    			continue;
    		}
		}
		delete input;
	}

	bool is_valid(char *input , int lenght){
		for(int i = 0 ; i < lenght ; ++i){
			bool eq = false;
			for(int j = i-1 ; j >= 0 ; --j){
				if(input[j] == input[i]){
					return false;
				}
			}

			for(int j = 0 ; j < 10 ; ++j){
				if( input[i] == slovar[j]){
					eq = true;
					break;
				}
			}
			if(!eq){
				return false;
			}
		}
		return true;
	}

private:
    char slovar[10] = {'0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9'};
    Sequence *sec;
    int turns;
};

#endif