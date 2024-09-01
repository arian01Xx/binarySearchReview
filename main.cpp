#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution{
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
		unordered_set<int> st(nums1.begin(), nums1.end());
		vector<int> ans;
		for(int n: nums2){
			if(st.erase(n)) ans.push_back(n);
		} 
		return ans;
	}
};

struct TrieNode{
	vector<TrieNode*> child{vector<TrieNode*>(26,nullptr)};
	string* word{};
};

void insert(TrieNode* root, string& word){
	for(char c: word){
		c -= 'a';
		//si no existe lo agrega
		if(root->child[c]==nullptr) root->child[c]=new TrieNode();
		root=root->child[c];
	}
	root->word= &word;
}

void dfs(TrieNode* root, int limit, vector<string>& result){
	if(root=nullptr) return;
	if(result.size()==limit) return;
	if(root->word != nullptr) result.push_back(*root->word);
	for(int i=0; i<26; ++i){
		dfs(root->child[i], limit, result);
	}
}

vector<string> getWords(TrieNode* root, int limit){
	vector<string> result;
	dfs(root, limit, result);
	return result;
}

class SolutionOne{
public:
	vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord){
		TrieNode* root= new TrieNode();
		for(string& product: products) insert(root, product);
		vector<vector<string>> ans;
	    TrieNode* curr=root;
	    for(char& c: searchWord){
	    	c -= 'a';
	    	if(curr != nullptr && curr->child[c]!=nullptr){
	    		curr=curr->child[c];
	    		ans.push_back(getWords(curr,3));
	    	}else{
	    		curr=nullptr;
	    		ans.emplace_back();
	    	}
	    }
	    return ans;
	}
};

void printVector(vector<int> list){
	for(const auto& num: list){
		cout<<num<<" ";
	}
	cout<<endl;
}

void printVectorString(vector<string> output){
	for(const auto& atom: output){
		cout<<atom<<" ";
	}
	cout<<endl;
}

void printVector2Dstring(vector<vector<string>> elements){
	for(const auto& caca: elements){
		vector<string> pipi=caca;
		printVectorString(pipi);
	}
	cout<<endl;
}

int main(){

	cout<<"Binary search successful! "<<endl;
	vector<int> nums1={1,2,2,1};
	vector<int> nums2={2,2};
	Solution solution;
	vector<int> output=solution.intersection(nums1,nums2);
	cout<<"inputs two vectors: "<<endl;
	printVector(nums1); printVector(nums2);
	cout<<"output: "<<endl;
	printVector(output);

	return 0;
}