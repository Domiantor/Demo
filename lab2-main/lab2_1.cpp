#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main ()
{
   FILE *fp;
   char c;
   int i,cnt=0,cnt1=0,cnt2=0,ss[100];
   int j=0;
   int level=0;
   string str;
   string ans[100];
   stack<char>s;
   char file_path[100];
   cout<<"请输入文件路径：";
   cin>>file_path;
   cout<<"请输入等级：";
   cin>>level;
   string a[35]={"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
   fp = fopen(file_path,"r");
   while((c = fgetc(fp))!=EOF){
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){//预处理删除掉一些无关的数据
   	      str+=c;
        }
       else{
	      if(str!=""){
	        for(i=0;i<35;i++){
	  	   if(str==a[i]){//判断关键词总数
	  		 cnt++;
	  		 if(i==25){//判断switch个数
		   	   cnt1++;
		   	   if(s.empty()){
		   	     s.push('s');
		   	    }
		     }
		     if(i==2&&s.top()=='{'){
		     	cnt2++;
			 }
		   }
	      }
	      str="";
	    }
	    else{
	    	if((c=='{')&&(!s.empty())){
	          s.push(c);
			}	
			if((c=='}')&&(!s.empty())){//判断case个数
				s.pop();
				s.pop();
				ss[j++]=cnt2;
		   	    cnt2=0;
			}
		}
      }
      
  }
   cout<<"total num: "<<cnt<<endl;
   cout<<"switch num: "<<cnt1<<endl;
   cout<<"case num: ";
   for(i=0;i<j;i++){
   	cout<<ss[i]<<" ";
   }
   cout<<endl;
   fclose(fp);
 
}
