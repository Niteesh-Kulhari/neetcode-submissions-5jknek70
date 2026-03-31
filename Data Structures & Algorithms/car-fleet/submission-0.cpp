class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> carSpeed;

        for(int i=0; i<n; i++){
            carSpeed.push_back({position[i], speed[i]});
        }

        sort(carSpeed.begin(), carSpeed.end());

        vector<double> st;
        for(int i=n-1; i>=0; i--){
            int distance = target - carSpeed[i].first;
            double time = (double)distance / carSpeed[i].second;
            st.push_back(time);

            if(st.size() >= 2 && st.back() <= st[st.size()-2]){
                st.pop_back();
            }


        }

        // for(int i=0; i<n; i++){
        //     cout << "Position: " << carSpeed[i].first << " and the speed is " << carSpeed[i].second;
        //     cout << endl;
        // }


        return st.size();

    }
};
