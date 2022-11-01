#include <gtest/gtest.h>

#include "disemvowel.h"

void test_strings(const char* input, const char* result) {
  char* str = disemvowel((char*) input);
  ASSERT_STREQ(result, str);
  free(str);
}

TEST(Disemvowel, HandleEmptyString) {
  test_strings("", "");
}

TEST(Disemvowel, HandleNoVowels) {
  test_strings("pqrst","pqrst");
}

TEST(Disemvowel, HandleOnlyVowels) {
  test_strings("aeiouAEIOUOIEAuoiea", "");
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  test_strings("Morris, Minnesota", "Mrrs, Mnnst");
}

TEST(Disemvowel, HandlePunctuation) {
  test_strings("An (Unexplained) Elephant!", "n (nxplnd) lphnt!");
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  
  char* dv = disemvowel((char*)str);
  ASSERT_STREQ("xyz", dv);
  free(dv);

  free(str);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
