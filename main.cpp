#include <iostream>

using namespace std;

int main() {
    string s;
	cin >> s;
	
    int ings = 9;
	int len = s.length();
	long long A[10][len+1];
	int prev[10][len+1];
	
    for (int i = 0; i < 10; i++){
		for (int j = i; j < len+1; j++){
            if (i == 0){
                A[i][j] = 0;
			}else{
				long long max = -1;
				long long bestCurr = -1;
				int bestK = bestCurr = -1;
				int start = i-1;
				
                if (j - 17 > start){
					start = j-17;
				}
                
				for (int k = start; k <= j-1; k++){
                    string s2 = s.substr(k, j-k);
					
					long long curr = stoll(s2);
                    
					if (curr + A[i-1][k] > max){
						max = curr + A[i-1][k];
						bestCurr = curr;
						bestK = k;
					}
				}
                
				A[i][j] = max;
				prev[i][j] = bestK;
			}
		}
	}
    
	int currK = len;
	string result = "";
    
	for (int i = 9; i >= 1; i--){
		int nextK = prev[i][currK];
		string s2 = s.substr(nextK, currK - nextK);
		
        if (i < 9){
			result = "|" + result;
		}
        
		result = s2 + result;
		currK = nextK;
		
	}
    
	cout << result << endl;
	cout << "Total: " << A[9][len] << endl;
}
