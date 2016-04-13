#include "GameManager.h"
using namespace std;
#include <ostream>

const GameList GameManager::operator[](const Date& d) const
{
	int i;
	GameList res;
	res.count=0;
	for(int i =0 ; i < 5;i++){
		const TimeAndDate t =*m_games[i].GetTimeAndDate();
		if(t.GetDate()== d)
			res.games[res.count++] = m_games[i];
	}
	return res;
}

const GameList GameManager::operator[](const TimeAndDate& tad) const
{
	int i;
	GameList res;
	res.count=0;
	for(int i =0 ; i < 5;i++){
		if(*(m_games[i].GetTimeAndDate())== tad)
			res.games[res.count++] = m_games[i];
	}
	return res;
}

void GameManager::CancelGame(){
	Game gameToCancel();
	//get the game 

}

void GameManager::SendInvitations(){
//we need an array of all inlisted people.
	int length;
	for(int i=0;i<length;i++){

	}

}
void GameManager::SellTickets(){
//we need an array of all inlested people.
	int length;
	Game g();
	Fan *fans;
	for(int i=0;i<length;i++){
		//put the randomly selected people in the game fan array
	}
}

void GameManager::ManageTrainers(){
	//get game length.
	int length;
	char* name,*f_name;
	long id;
	for(int i=0;i<length;i++)
	{
		cout<<"\nteam number "<<i<<".\nenter Name :";
		cin>>name;
		cout<<"\nenter first Name :";
		cin>>f_name;
		cout<<"\nenter id :";
		cin>>id;
		m_teams[i].AddTrainer(new Trainer(name,f_name,id));
	}
}

void GameManager::ManageReferees(){
	int numberOfReferees;
	cout<<"Please enter number of Referees : "<<endl;
	cin >>numberOfReferees;
	char*name,*f_name;
	long id;
	for(int i =0 ; i < numberOfReferees;i++)
	{
		cout<<"\nenter Name:";
		cin>>name;
		cout<<"\nenter first name :";
		cin >>f_name;
		cout<<"\nenter id: ";
		cin>>id;
		m_referees[i] = Referee(name,f_name,id);
	}
}

void GameManager::ManageTeams(){
	int numberOfTeams,numberOfP,level,pnum,type;
	char*name,*f_name;
	long id;
	Player *p =NULL;
	cout<<"Please enter number of Referees : "<<endl;
	cin >>numberOfTeams;

	for(int i =0 ; i < numberOfTeams;i++)
	{
		cout<<"\nTeam number : "<<i<<" \nenter Name:";
		cin>>name;
		m_teams[i] = Team(name);
		cout<<"\nnumber of Players in the team :";
		cin>>numberOfP;
		for(int i=0 ;i<numberOfP;i++)
		{
			
			cout<<"\ntype of Player :: 1-forwarder , 2- Defender,3-GoalKeeper";
			cin>>type;
			cout<<"\nPlayer name: ";
			cin >>name;
			cout<<"\nPlayer first name : ";
			cin>>f_name;
			cout<<"\nPlayer id: ";
			cin >>id;
			cout<<"\nPlayer Level, 0 if Default : ";
			cin>>level;	
			switch(type)//get the movment +=.... for each Player -> user input in there
			{
			case 1: m_teams[i] += new Forwarder(name,f_name,id,pnum,&m_teams[i],Player::PlayerLevel(level));		break;
			case 2: m_teams[i] += new Defender(name,f_name,id,pnum,&m_teams[i],Player::PlayerLevel(level));			break;
			case 3: m_teams[i] += new GoalKeeper(name,f_name,id,pnum,&m_teams[i],Player::PlayerLevel(level));		break; 
			// in each player we set the movments from the user.	
			}
			m_teams[i]+=p;
		}

	}
	ManageTrainers();//we run we each team gets a trainer
}

void GameManager::ManageGames(){
	char yn='Y';
	int c =1;
	while(c==1|c==2)
	{
	cout<<"\nPlease enter Choice :\n 1-Add Game , 2-Cancel Game else-exit";
	cin>>c;
	switch(c)
	{
	case 1:
		while(yn=='Y'){
			cout<<"\nWould you like to add a new Game? : Y -yes,N-no";
			cin>>yn;
			if(yn=='Y'){
				NewGame();
			}
		}
	case 2:
		while(yn=='Y'){
			cout<<"\nWould you like to Cancel Game? : Y -yes,N-no";
			cin>>yn;
			if(yn=='Y'){
				CancelGame();
			}
		}
	}
	}

}

void GameManager::NewGame(){
	Game *g = NULL;
	Team* teams;
	int t1,t2,minutes,hours,day,month,year,maxFans,length;
	cout<<"\nPlease enter Team number 1 id :- ";
	cin>>t1;
	cout<<"\nPlease enter Team number 2 id :- ";
	cin>>t2;
	teams[0]=m_teams[t1];
	teams[1]=m_teams[t2];
	//if would like to search for it instead - in STL phase would be convenient
	cout<<"\nenter date :  day month year :: ";
	cin >>day>>month>>year;
	cout<<"\nenter time :  hourse minutes :: ";
	cin >>hours>>minutes;
	cout <<"\nPlease enter number of maximum fans : ";
	cin >>maxFans;
	Date d = Date(day,month,year);
	Time t = Time(hours,minutes);
	TimeAndDate tad = TimeAndDate(t,d);
	g = new Game(teams,tad,maxFans);
	//this += g;    needs work!!
}


const GameManager& GameManager::operator+=(const Game& g)
{	//search for stadium fit for the game
	//s_length the length of the stadium array
	int s_length,length;
	m_games[length] = g;
	for(int i=0;i<s_length;i++)
	{
		if(m_stadiums[i].GetMaxFans() > g.GetMaxFans())
		{
			TimeAndDate tad = *m_games[length].GetTimeAndDate();
			if(m_stadiums[i].GetGamesByDate(tad.GetDate())!=NULL)
			{
				m_stadiums[i].AddGame(&m_games[length]);
				break;
			}

		}
	}
	length++;
	s_length++;
}

