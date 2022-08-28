// IntentTests.cpp
#include "IntentRecognition.cpp"
#include <gtest/gtest.h>

using testing::ElementsAre;
using testing::Pair;
 
TEST(PrepareIntentTest, MapValidation) {
	
	IntentClassifier Obj;
	Obj.IntentMap.insert(std::pair<string, regex>("Intent: Get Fact","[Ff][Aa][Cc][Tt]"));
	Obj.IntentMap.insert(std::pair<string, regex>("Intent: Get Weather","[Ww][Ee][Aa][Tt][Hh][Ee][Rr]"));
	Obj.IntentMap.insert(std::pair<string, regex>("Intent: Get Weather City","[Ww][Ee][Aa][Tt][Hh][Ee][Rr](.*)[in]"));
	
	EXPECT_THAT(Obj.prepareIntent(), ElementsAre(Pair("Intent: Get Fact", "[Ff][Aa][Cc][Tt]"), Pair("Intent: Get Weather", "[Ww][Ee][Aa][Tt][Hh][Ee][Rr]"), Pair("Intent: Get Weather City", "[Ww][Ee][Aa][Tt][Hh][Ee][Rr](.*)[in]")));
}

TEST(extractIntentTest, StringValidation1) {
	
	IntentClassifier Obj;
	Obj.IntentMap.insert(std::pair<string, regex>("Intent: Get Fact","[Ff][Aa][Cc][Tt]"));
	Obj.IntentMap.insert(std::pair<string, regex>("Intent: Get Weather","[Ww][Ee][Aa][Tt][Hh][Ee][Rr]"));
	Obj.IntentMap.insert(std::pair<string, regex>("Intent: Get Weather City","[Ww][Ee][Aa][Tt][Hh][Ee][Rr](.*)[in]"));
	
	EXPECT_EQ(true, Obj->extractIntent("What's the weather today"));
}

TEST(extractIntentTest, StringValidation2) {
	
	IntentClassifier Obj;
	Obj.IntentMap.insert(std::pair<string, regex>("Intent: Get Fact","[Ff][Aa][Cc][Tt]"));
	Obj.IntentMap.insert(std::pair<string, regex>("Intent: Get Weather","[Ww][Ee][Aa][Tt][Hh][Ee][Rr]"));
	Obj.IntentMap.insert(std::pair<string, regex>("Intent: Get Weather City","[Ww][Ee][Aa][Tt][Hh][Ee][Rr](.*)[in]"));
	
	EXPECT_EQ(false, Obj->extractIntent("What's the distance of TajMahal from my current location"));
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}