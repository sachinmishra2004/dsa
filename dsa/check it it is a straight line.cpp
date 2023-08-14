class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n =  coordinates.size();

        // (x1,y1),(x2, y2)  (x3, y3);
        //[ [1,2],   [2,3],  [3,4],[4,5],[5,6],[6,7]]
        //using formula like M = (y2-y1) / (x2-x1);
                        //index
                          //  | 
        int d_y = coordinates[1][1] - coordinates[0][1]; // y2-y1;
        int d_x = coordinates[1][0] - coordinates[0][0]; //x2-x1;

        /*
        slope ,  M =  Y2-Y1/X2-X1
                      
        */
        // NOW O  to from 2 tak slope

        for(int i =2; i<n; i++){
            int d_y_i = coordinates[i][1] - coordinates[0][1];
            int d_x_i = coordinates[i][0] - coordinates[0][0];

            /*
              slope =   d_y-i/d_x_i
                        d_y_i*d_x ==d_y*d_x_i;
            */
            if(!(d_y_i*d_x ==d_y*d_x_i)){
                return false;
            }
        }
        return true;


    }
};