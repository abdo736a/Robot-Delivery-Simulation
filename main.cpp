// ENG.Abdelrhman Hamdy (#Abdo736a)

#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

static int X = 10;
static int Y = 10;



string getCurrentDateTime() {
    time_t now = time(0);
    char buf[80];
    struct tm tstruct;
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct); 
    return buf;
}

string getCurrentDateTime2() {
    time_t now = time(0);
    char buf[80];
    struct tm tstruct;
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d %H_%M_%S", &tstruct); 
    return buf;
}

// CREATING A FILE 
ofstream logFile("robot_log_" + getCurrentDateTime2() + ".txt");

// ROBOT OOP
class robot{
    private:
    int x;
    int y;
    int moveCount;
    public:

    robot(){
    x = 0;
    y = 0;
    moveCount = 0;
    };

    void moveRobot(char);
    void showStatus();
    int  getData(char);
};

    void robot::moveRobot(char direction){
        if (direction == 'U'){
        if (this->y < Y){
            y++;
            moveCount++;
        }else{
            cout << "Invaild move \n";
            logFile << "Invaild move \n";
        }
        }else if(direction == 'D'){
            if (this->y <= 0){
                cout << "Invaild move \n";
                logFile << "Invaild move \n";
            } else {
                y--;
                moveCount++;
            }
        }else if (direction == 'R'){
        if (this->x < X){
            x++;
            moveCount++;
        }else{
            cout << "Invaild move \n";
            logFile << "Invaild move \n";
        }
        }else if (direction == 'L'){
        if (this->x <= 0){
            cout << "Invaild move \n";
            logFile << "Invaild move \n";
        }else{
            x--;
            moveCount++;
        }
        }else{
            cout << "Invaild direction !" << endl;            
            logFile << "Invaild direction !" << endl;            
        }
        cout << "Robot direction X = (" << this->x << ")  Y = (" << this->y << ") moves : (" << moveCount << ") \n";
        logFile << "Robot direction X = (" << this->x << ")  Y = (" << this->y << ") moves : (" << moveCount << ") \n";
        
    }

    void robot::showStatus(){
        cout << "Robot direction X = (" << this->x << ")  Y = (" << this->y << ") moves : (" << moveCount << ") \n";
        logFile << "Robot direction X = (" << this->x << ")  Y = (" << this->y << ") moves : (" << moveCount << ") \n";
    }

    int robot::getData(char dir){
        if (dir == 'x') return this->x;
        if (dir == 'y') return this->y;
        if (dir == 'm') return this->moveCount;
        return 1;
    }
    

    /////

class deliveryPoint{
    private:
    int x;
    int y;
    string itemName;
    bool delivered;
    public:
    deliveryPoint(int x,int y,string itemName){
        this->x = x;
        this->y = y;
        this->itemName = itemName;
        delivered = false;
    }
    void makeDeliverd();
    bool getDeliverdStatus();
    int getPos(char);
};
    void deliveryPoint::makeDeliverd(void){
        this->delivered = true;
        cout << "The robot deliverd (" << this->itemName <<  ") successfully! ";       
        logFile << "The robot deliverd (" << this->itemName <<  ") successfully! ";       
     
    }

    bool deliveryPoint::getDeliverdStatus(){
        return this->delivered;
    }

    int deliveryPoint::getPos(char dir){
        if (dir == 'x') return this->x;
        if (dir == 'y') return this->y;
        return 1;
    }    

int main(){

    logFile << "Log file for new proccess for date : " << getCurrentDateTime() << " \n";    

    int points_count = 3;
    deliveryPoint *points[points_count];
    points[0] = new deliveryPoint(3,4,"pack. 1");
    points[1] = new deliveryPoint(1,2,"pack. 2");
    points[2] = new deliveryPoint(8,5,"pack. 3");
    ////

    robot Robot_1;
    char dir;
    

    while (true)
    {
    cout << "\nenter move (U/D/L/R) or Q to quit: ";
    logFile << "\nenter move (U/D/L/R) or Q to quit: ";
    cin >> dir; 
        
    if ( dir == 'Q' ) break;
    
    Robot_1.moveRobot(dir);
    for(int i=0;i<points_count;i++){
        if (!points[i]->getDeliverdStatus() && points[i]->getPos('x') == Robot_1.getData('x') && points[i]->getPos('y') == Robot_1.getData('y')){
            points[i]->makeDeliverd();
            cout << "with count moves : (" << Robot_1.getData('m') << ") \n";
            logFile << "with count moves : (" << Robot_1.getData('m') << ") \n"; 
        }
    }

    for(int i=0;i<Y;i++){
        for(int j=0;j<X;j++){
            char cell = '.';

            for(int p=0;p<points_count;p++){
                if (points[p]->getPos('y') == i && points[p]->getPos('x') == j){
                    if (points[p]->getDeliverdStatus()){
                        cell = 'X';
                    }else{
                        cell = 'D';
                    }
                    break;
                }
            }

            if (Robot_1.getData('y') == i && Robot_1.getData('x') == j){
                cell = 'R';
            }

            cout << cell << " ";
            logFile << cell << " ";
        }
        cout << endl;
        logFile << endl;
    }

    bool allDelivered = true;
    for(int i=0;i<points_count;i++){
        if (!points[i]->getDeliverdStatus()){
            allDelivered = false;
            break;
        }
    }
    if (allDelivered){
        cout << "All packs delivered";
        logFile << "All packs delivered";

        for(int i=0;i<points_count;i++){
        delete points[i];
        }        
        logFile << "\n ==============================================\n";
        logFile.close();
        break;
    }

    }
    
    return 0;
}
