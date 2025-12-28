int kadane(vector<int>& vec){
    int globalMax = vec[0], localMax = vec[0];
    int globalMin = vec[0], localMin = vec[0];
    int sum = vec[0];
    for(int i = 1; i < vec.size(); i++){
                 localMax = max(vec[i], localMax+vec[i]);
                 globalMax = max(globalMax, localMax);
                 localMin = min(vec[i], localMin+vec[i]);
                 globalMin = min(globalMin, localMin);
                 sum += vec[i];
    } /*
    In case of circular array
    if(globalMin == sum)
        return globalMax;
    else
        return max(globalMax, sum-globalMin);
    */
    return globalMax;
}
int kadane2d(vector<vector<int> >& matrix){
    int maxValue = -INF;
    for(int i = 0; i < matrix[0].size(); i++){
        vector<int> aux(matrix.size(),0);
        for(int j = i; j < matrix[0].size(); j++){
            for(int k = 0; k < aux.size(); k++) aux[k] += matrix[k][j];
                maxValue = max(maxValue, kadane(aux));
        }
    }
    return maxValue;
}