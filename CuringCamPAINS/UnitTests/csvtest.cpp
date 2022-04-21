#include "csvtest.h"
#include "vector"
CsvTest::CsvTest() {
}


TEST(CSV,successWriteReadTest ) {
    Csv *c;
    c=new Csv();
    c->writeFile("../../unitest_file.csv","a,b,c");
    c->readFile("../../unitest_file.csv");
    vector<vector<string>> expected;
    expected={{"a","b","c"}};
    vector<vector<string>> result=c->content;
    bool res=false;
    if (expected== result){
        res=true ;
    }

    ASSERT_EQ(res,true);
}


TEST(CSV,failureWriteReadTest ) {
    Csv *c;
    c=new Csv();
    c->writeFile("../../unitest_file.csv","a,b,c");
    c->readFile("../../unitest_file.csv");
    vector<vector<string>> expected;
    expected={{"a","b","b"}};
    vector<vector<string>> result=c->content;
    bool res=false;
    if (expected == result){
        res=true ;
    }

    ASSERT_EQ(res,false);
}
