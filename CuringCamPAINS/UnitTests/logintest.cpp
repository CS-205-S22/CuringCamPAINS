#include "logintest.h"

LoginTest::LoginTest() {
}


TEST(login,LoginSuccessTest ) {
   Login *l;
    l=new Login("../../test.sqlite");
    bool result=l->signUp("rakotozt", "blabla");
    bool expected=true;
    ASSERT_EQ(result, expected);

}

TEST(login,LoginFailureTest ) {
   Login *l;
    l=new Login("../../test.sqlite");
    bool result=l->signUp("rakotozt", "blabl");
    bool expected=false;
    ASSERT_EQ(result, expected);

}
