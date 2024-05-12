#include <cstddef>
#include <gtest/gtest.h>
#include "Autocomplete.h"



class AutocompleteTest: public ::testing::Test{
    protected:
        Autocomplete ac;
        
        // functions to insert multiple words into the Autocomplete {object
        void insertWords(const std::vector<std::string> & words)
        {
            for (const auto& word: words){
                ac.insert(word);
            }
        }


        // Functions to comapre two vector of strings
        bool compareVectors(const std::vector<std::string>& vec1, const std::vector<std::string>& vec2){
            if (vec1.size() != vec2.size()) return false;

            for (size_t i = 0; i< vec1.size(); ++i){
                if (vec1[i] != vec2[i]) return false;
            }

            return true;
        }
};


// Test case for getSuggestions() method
TEST_F(AutocompleteTest, TestGetSuggestions){
    // Insert some words into the Autocomplete object
    insertWords({"banana", "bandaid", "bandana"});

    // test for partial word "ban"
    std::vector<std::string> expected1 = {"banana", "bandaid", "bandana"};
    EXPECT_TRUE(compareVectors(ac.getSuggestions("ban"), expected1));


    // test for partial word "band"
    std::vector<std::string> expected2 = {"bandaid", "bandana"};
    EXPECT_TRUE(compareVectors(ac.getSuggestions("band"), expected2));


    // test for partial word "bana"
    std::vector<std::string> expected3 = {"banana", "bandana"};
    EXPECT_TRUE(compareVectors(ac.getSuggestions("ban"), expected3));

    // Test for partial word "ball"
    std::vector<std::string> expected4;
    EXPECT_TRUE(compareVectors(ac.getSuggestions("ball"), expected4));
}


int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}