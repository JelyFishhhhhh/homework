#include<bits/stdc++.h>
using namespace std;
// #define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

signed main(){
    //fastio;
    // vector<vector<int>> map;     // map
    // map.resize(50);
    // for(int x=0; x<50; x++){
    //     map[x].assign(50, 0);
    // }
    int map[50][50] = {0};
    bool pen = false;               // 0 == pen up, 1 == pen down
    int direction = 0;              // 0 == up, 1 == right, 2 == down, 3 == left
    string cmd;                     // avoid special input e.g. cmd == 5
    int location[2] = {0};          // location[0] == x-coordinate, location[1] == y-coordinate
    
    while(cin>>cmd && cmd != "9"){  // if cmd == 9 : break loop

        if (cmd[0] == '1'){

            pen = false;
        
        }
        else if (cmd[0] == '2'){
        
            pen = true;
        
        }
        else if (cmd[0] == '3'){
        
            direction ++;
            direction %= 4;         // redirect 0~3 position
        
        }
        else if (cmd[0] == '4'){
        
            direction --;
            direction += 4;         // redirect 0~3 position
            direction %= 4;
        
        }
        else if (cmd[0] == '5'){
        
            string cmd_sub = cmd.substr(cmd.find(',') + 1, cmd.length());  // get step value
            
            // str2int
            int step = 0;
            for (int x = 0; x < cmd_sub.length(); x++){
        
                if(step != 0){
        
                    step *= 10;
        
                }
        
                step += cmd_sub[x] - '0';
        
            }
            
            switch (direction){
            
            case 0:
                
                for (int y = 0; y < step && location[1] + 1 <= 50; y++){
        
                    if(pen == true){
        
                        map[location[0]][location[1]+1] = 1;
        
                    }
        
                    location[1] ++;
        
                }

                break;
            
            case 1:
                
                for (int x = 0; x < step && location[0] + 1 <= 50; x++){
        
                    if(pen == true){
        
                        map[location[0]+1][location[1]] = 1;
        
                    }
        
                    location[0] ++;
        
                }
                
                break;
            
            case 2:
                
                for (int y = 0; y < step && location[1] - 1 >= 0; y++){
        
                    if(pen == true){
        
                        map[location[0]][location[1]-1] = 1;
        
                    }
        
                    location[1] --;
        
                }

                break;
            
            case 3:
                
                for (int x = 0; x < step && location[0] - 1 >= 0; x++){
        
                    if(pen == true){
        
                        map[location[0]-1][location[1]] = 1;
        
                    }
        
                    location[0] --;
        
                }

                break;
            
            
            default:
        
                break;
        
            }
        
        }
        else if (cmd[0] == '6'){
        
            for (int y = 0 ; y < 50 ; y++){
        
                for (int x = 0 ; x < 50 ; x++){
        
                    if(map[x][y] == 1){
        
                        cout<<'*';
        
                    }
        
                    else{
        
                        cout<<' ';
        
                    }
        
                }
        
                cout<<'\n';
        
            }
        
        }
    }
}


/*==============================================

Example Input:

2
5,12
3
5,12
3
5,12
3
5,12
1
6
9

================================================

Example Output:

*************
*           *
*           *
*           *
*           *
*           *
*           *
*           *
*           *
*           *
*           *
*           *
*************






































==============================================*/
