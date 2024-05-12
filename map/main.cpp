#include <atomic>
#include <cstdint>
#include <iostream>


// Including the required libraries 
#include <vector>
#include <unordered_map> // unordered map (self-balancing binary tree - implemented by red black tree)
#include <map> // sorted map

struct CityRecord{
    std::string Name;
    uint64_t Population;
    double Latitude, Longitude;
};


// Create a template specialization specialized for the hashed key

namespace std{
    template<> // template specialization 
    struct hash<CityRecord>
    { //
        size_t operator()(const CityRecord& key) // provide reference to key that will be hashing 
        {
            // Suppose we want to hash the Name attribute. Let's see how.
            return hash<std::string>()(key.Name); // we have to construct and provide 
        }

    };
};





int main(int argc, char** argv){
    // std::pair<int, std::string> p1 = {13, "hellsdo"};
    // std::pair<int, std::string> p2 = {15, "he4lo2"};
    // std::pair<int, std::string> p3 = {16, "he5ldsafo"};
    // std::pair<int, std::string> p4 = {17, "hsdaae6lo"};

    // std::map<int, std::string> orderedMap{p1, p2, p3, p4};

    // // Printing ordered map
    // int i = 0; 
    // for (std::pair p: orderedMap){   
    //     std::cout << ++i << ": " << p.first << " --> " << p.second << std::endl;
    // }

    // Why use map? Let's exhibit the advantage of map in comparison with our 
    // good ol' dynamic array or vector 
    // std::vector<CityRecord> cities;

    // cities.push_back({"Melbourne", 500000,9292,562332});
    // cities.push_back({"Phnom Penh", 500000,9292,212332});
    // cities.push_back({"Bern", 50540,5192,2335452});
    // cities.push_back({"Brisbane", 43000,921392,2312332});
    // cities.push_back({"Adelaide",342000,9242,22132});

    ///////////////////////// let's try to retrieve information out of a specific city 
    // for (const auto city: cities){
    //     if (city.Name == "Bern"){
    //         // process Bern's data 
    //         std::cout << city.Longitude << std::endl;
    //     }
    // }
    // If the vector is unsorted and completely random, then the worst case scenario is that we will have done N string-comparisons, where N is the size of the vector. 
    // If the vector is sorted, we can use binary search to optimize it in some way. 

    // std::map<std::string, CityRecord> cityMap;
    // cityMap["Melbourne"] = CityRecord({"Melbourne", 500000,9292,562332});
    // cityMap["Phnom Penh"] = CityRecord({"Phnom Penh", 500000,9292,212332});
    // cityMap["Bern"] = CityRecord({"Bern", 50540,5192,2335452});
    // cityMap["Brisbane"] = CityRecord({"Brisbane", 43000,921392,2312332});
    // cityMap["Adelaide"] = CityRecord({"Adelaide",342000,9242,22132});


    // Retrieve information about Adelaide
    // CityRecord& adelaideData = cityMap["Adelaide"];
    // std::cout << adelaideData.Population << std::endl;


    std::unordered_map<CityRecord, uint32_t> foundedMap;
    // foundedMap["Melbourne"] = CityRecord{"Melbourne", 500000,9292,562332};
    // foundedMap["Phnom Penh"] = CityRecord({"Phnom Penh", 500000,9292,212332});
    // foundedMap["Bern"] = CityRecord({"Bern", 50540,5192,2335452});
    // foundedMap["Brisbane"] = CityRecord({"Brisbane", 43000,921392,2312332});
    // foundedMap["Adelaide"] = CityRecord({"Adelaide",342000,9242,22132});
    foundedMap[CityRecord{"Melbourne", 500000,9292,562332}] = 1850; 
    foundedMap[CityRecord{"Melbourne", 500000,9292,562332}] = 1850; 
    foundedMap[CityRecord{"Melbourne", 500000,9292,562332}] = 1850; 
    foundedMap[CityRecord{"Melbourne", 500000,9292,562332}] = 1850; 

    // Since our key is of type CityRecord, it has to be hashable 
    // by default, the map doesn't hash non-trivial data type or compound data type such as struct or class
    // so we need to provide our own hash function 

    // On the other hand, if it had been CityRecord*, a pointer to type CityRecord, 
    // instead of CityRecord, the signifying the raw data in the RAM, then no error would occur
    // but a pointer's, at the end of the day (when the compiler parses it), is just 
    // an integer and so we might as well just use uint64_t instead of CityRecord* 

    


    
    /***
    @param hello 
    ***/
    // How to use unordered? Syntactically, almost identical as map 
    std::unordered_map<std::string, CityRecord> unordered_cityMap;
    // Whatever we use as the key is hashable. 
    unordered_cityMap["Melbourne"] = CityRecord{"Melbourne", 500000,9292,562332};
    unordered_cityMap["Phnom Penh"] = CityRecord({"Phnom Penh", 500000,9292,212332});
    unordered_cityMap["Bern"] = CityRecord({"Bern", 50540,5192,2335452});
    unordered_cityMap["Brisbane"] = CityRecord({"Brisbane", 43000,921392,2312332});
    unordered_cityMap["Adelaide"] = CityRecord({"Adelaide",342000,9242,22132});

    // Indexing operator ==> automatically insert your key into the map 
    CityRecord& adelaideData = unordered_cityMap["Adelaide"]; // returns a reference an already in-place memory 
    adelaideData.Name = "";
    adelaideData.Population = 219921;
    // Advantage: we don't need to set it again in the future. The code below does 
    // exactly the same task as the code above. But there's an overhead of 
    // creating the data in the stack and then copying them into the created map.
    CityRecord adelaideData1;
    adelaideData1.Name = "Berlin";
    adelaideData1.Population = 1000;
    unordered_cityMap["Adelaide"] = adelaideData1; 
    
    // If we don't want to insert element, then use at() - retrieving it 
    // And if you happen to have a const map below
    const auto & cities = unordered_cityMap;
    // CityRecord& data = cities["Bern"];
    // Then using the usual indexing [] operator won't work because it violates the 
    // const's rule, which is the data that is assigned the keyword const must be immutable and 
    // the [] operator doesn't guarantee that. Hence, we need to use at () instead. 

    // const CityRecord& data = cities.at("Bern");
    // Remember that it will also return a const reference of that object, hence the const keyword at the front 
    

    // If the data ismn't there, or if "Bern" isn't there, an error or exception will be thrown so use find()

    // if (cities.find("Bern") != cities.end()){
    //     const CityRecord& data = cities.at("Bern");
    // }
    

    // Iterating through your map (although almost always slower than iterating through a vector)

    // Stone-age way of iterating through maps 
    // for (auto& kv: unordered_cityMap){
    //     // const std::string& name = kv.first;
    //     // CityRecord& city = kv.second;
    // }

    // C++ 17
    for (const auto&[name, city]: unordered_cityMap) { // use structure binding 
        std::cout << "Name: " << name << "\t" << "Population: "  << city.Population << std::endl; // error!!!
    }
    /*
    In file included from /usr/include/c++/11/bits/hashtable.h:35,
                 from /usr/include/c++/11/unordered_map:46,
                 from main.cpp:8:
/usr/include/c++/11/bits/hashtable_policy.h: In instantiation of ‘std::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Hash, _RangeHash, _Unused, __cache_hash_code>::__hash_code std::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Hash, _RangeHash, _Unused, __cache_hash_code>::_M_hash_code(const _Key&) const [with _Key = CityRecord; _Value = std::pair<const CityRecord, unsigned int>; _ExtractKey = std::__detail::_Select1st; _Hash = std::hash<CityRecord>; _RangeHash = std::__detail::_Mod_range_hashing; _Unused = std::__detail::_Default_ranged_hash; bool __cache_hash_code = true; std::__detail::_Hash_code_base<_Key, _Value, _ExtractKey, _Hash, _RangeHash, _Unused, __cache_hash_code>::__hash_code = long unsigned int]’:
/usr/include/c++/11/bits/hashtable_policy.h:729:45:   required from ‘std::__detail::_Map_base<_Key, _Pair, _Alloc, std::__detail::_Select1st, _Equal, _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits, true>::mapped_type& std::__detail::_Map_base<_Key, _Pair, _Alloc, std::__detail::_Select1st, _Equal, _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits, true>::operator[](std::__detail::_Map_base<_Key, _Pair, _Alloc, std::__detail::_Select1st, _Equal, _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits, true>::key_type&&) [with _Key = CityRecord; _Pair = std::pair<const CityRecord, unsigned int>; _Alloc = std::allocator<std::pair<const CityRecord, unsigned int> >; _Equal = std::equal_to<CityRecord>; _Hash = std::hash<CityRecord>; _RangeHash = std::__detail::_Mod_range_hashing; _Unused = std::__detail::_Default_ranged_hash; _RehashPolicy = std::__detail::_Prime_rehash_policy; _Traits = std::__detail::_Hashtable_traits<true, false, true>; std::__detail::_Map_base<_Key, _Pair, _Alloc, std::__detail::_Select1st, _Equal, _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits, true>::mapped_type = unsigned int; std::__detail::_Map_base<_Key, _Pair, _Alloc, std::__detail::_Select1st, _Equal, _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits, true>::key_type = CityRecord]’
/usr/include/c++/11/bits/unordered_map.h:984:20:   required from ‘std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::mapped_type& std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::operator[](std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::key_type&&) [with _Key = CityRecord; _Tp = unsigned int; _Hash = std::hash<CityRecord>; _Pred = std::equal_to<CityRecord>; _Alloc = std::allocator<std::pair<const CityRecord, unsigned int> >; std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::mapped_type = unsigned int; std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::key_type = CityRecord]’
main.cpp:90:59:   required from here
/usr/include/c++/11/bits/hashtable_policy.h:1217:23: error: static assertion failed: hash function must be invocable with an argument of key type
 1217 |         static_assert(__is_invocable<const _Hash&, const _Key&>{},
      |                       ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/11/bits/hashtable_policy.h:1217:23: note: ‘std::__is_invocable<const std::hash<CityRecord>&, const CityRecord&>{}’ evaluates to false
/usr/include/c++/11/bits/hashtable_policy.h:1219:25: error: no match for call to ‘(const std::hash<CityRecord>) (const CityRecord&)’
 1219 |         return _M_hash()(__k);
      |                ~~~~~~~~~^~~~~
main.cpp:24:16: note: candidate: ‘std::size_t std::hash<CityRecord>::operator()(const CityRecord&)’ (near match)
   24 |         size_t operator()(const CityRecord& key) // provide reference to key that will be hashing
      |                ^~~~~~~~
main.cpp:24:16: note:   passing ‘const std::hash<CityRecord>*’ as ‘this’ argument discards qualifiers
In file included from /usr/include/c++/11/string:48,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/stl_function.h: In instantiation of ‘constexpr bool std::equal_to<_Tp>::operator()(const _Tp&, const _Tp&) const [with _Tp = CityRecord]’:
/usr/include/c++/11/bits/hashtable_policy.h:1617:39:   required from ‘bool std::__detail::_Hashtable_base<_Key, _Value, _ExtractKey, _Equal, _Hash, _RangeHash, _Unused, _Traits>::_M_equals(const _Key&, std::__detail::_Hashtable_base<_Key, _Value, _ExtractKey, _Equal, _Hash, _RangeHash, _Unused, _Traits>::__hash_code, const std::__detail::_Hash_node_value<_Value, typename _Traits::__hash_cached::value>&) const [with _Key = CityRecord; _Value = std::pair<const CityRecord, unsigned int>; _ExtractKey = std::__detail::_Select1st; _Equal = std::equal_to<CityRecord>; _Hash = std::hash<CityRecord>; _RangeHash = std::__detail::_Mod_range_hashing; _Unused = std::__detail::_Default_ranged_hash; _Traits = std::__detail::_Hashtable_traits<true, false, true>; std::__detail::_Hashtable_base<_Key, _Value, _ExtractKey, _Equal, _Hash, _RangeHash, _Unused, _Traits>::__hash_code = long unsigned int; typename _Traits::__hash_cached = std::__detail::_Hashtable_traits<true, false, true>::__hash_cached]’
/usr/include/c++/11/bits/hashtable.h:1840:23:   required from ‘std::_Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits>::__node_base_ptr std::_Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits>::_M_find_before_node(std::_Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits>::size_type, const key_type&, std::_Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits>::__hash_code) const [with _Key = CityRecord; _Value = std::pair<const CityRecord, unsigned int>; _Alloc = std::allocator<std::pair<const CityRecord, unsigned int> >; _ExtractKey = std::__detail::_Select1st; _Equal = std::equal_to<CityRecord>; _Hash = std::hash<CityRecord>; _RangeHash = std::__detail::_Mod_range_hashing; _Unused = std::__detail::_Default_ranged_hash; _RehashPolicy = std::__detail::_Prime_rehash_policy; _Traits = std::__detail::_Hashtable_traits<true, false, true>; std::_Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits>::__node_base_ptr = std::__detail::_Hashtable_alloc<std::allocator<std::__detail::_Hash_node<std::pair<const CityRecord, unsigned int>, true> > >::__node_base*; std::_Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits>::size_type = long unsigned int; std::_Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits>::key_type = CityRecord; std::_Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits>::__hash_code = long unsigned int]’
/usr/include/c++/11/bits/hashtable.h:810:31:   required from ‘std::_Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits>::__node_ptr std::_Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits>::_M_find_node(std::_Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits>::size_type, const key_type&, std::_Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits>::__hash_code) const [with _Key = CityRecord; _Value = std::pair<const CityRecord, unsigned int>; _Alloc = std::allocator<std::pair<const CityRecord, unsigned int> >; _ExtractKey = std::__detail::_Select1st; _Equal = std::equal_to<CityRecord>; _Hash = std::hash<CityRecord>; _RangeHash = std::__detail::_Mod_range_hashing; _Unused = std::__detail::_Default_ranged_hash; _RehashPolicy = std::__detail::_Prime_rehash_policy; _Traits = std::__detail::_Hashtable_traits<true, false, true>; std::_Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits>::__node_ptr = std::allocator<std::__detail::_Hash_node<std::pair<const CityRecord, unsigned int>, true> >::value_type*; std::_Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits>::size_type = long unsigned int; std::_Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits>::key_type = CityRecord; std::_Hashtable<_Key, _Value, _Alloc, _ExtractKey, _Equal, _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits>::__hash_code = long unsigned int]’
/usr/include/c++/11/bits/hashtable_policy.h:731:42:   required from ‘std::__detail::_Map_base<_Key, _Pair, _Alloc, std::__detail::_Select1st, _Equal, _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits, true>::mapped_type& std::__detail::_Map_base<_Key, _Pair, _Alloc, std::__detail::_Select1st, _Equal, _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits, true>::operator[](std::__detail::_Map_base<_Key, _Pair, _Alloc, std::__detail::_Select1st, _Equal, _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits, true>::key_type&&) [with _Key = CityRecord; _Pair = std::pair<const CityRecord, unsigned int>; _Alloc = std::allocator<std::pair<const CityRecord, unsigned int> >; _Equal = std::equal_to<CityRecord>; _Hash = std::hash<CityRecord>; _RangeHash = std::__detail::_Mod_range_hashing; _Unused = std::__detail::_Default_ranged_hash; _RehashPolicy = std::__detail::_Prime_rehash_policy; _Traits = std::__detail::_Hashtable_traits<true, false, true>; std::__detail::_Map_base<_Key, _Pair, _Alloc, std::__detail::_Select1st, _Equal, _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits, true>::mapped_type = unsigned int; std::__detail::_Map_base<_Key, _Pair, _Alloc, std::__detail::_Select1st, _Equal, _Hash, _RangeHash, _Unused, _RehashPolicy, _Traits, true>::key_type = CityRecord]’
/usr/include/c++/11/bits/unordered_map.h:984:20:   required from ‘std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::mapped_type& std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::operator[](std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::key_type&&) [with _Key = CityRecord; _Tp = unsigned int; _Hash = std::hash<CityRecord>; _Pred = std::equal_to<CityRecord>; _Alloc = std::allocator<std::pair<const CityRecord, unsigned int> >; std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::mapped_type = unsigned int; std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::key_type = CityRecord]’
main.cpp:90:59:   required from here
/usr/include/c++/11/bits/stl_function.h:370:20: error: no match for ‘operator==’ (operand types are ‘const CityRecord’ and ‘const CityRecord’)
  370 |       { return __x == __y; }
      |                ~~~~^~~~~~
In file included from /usr/include/c++/11/iosfwd:40,
                 from /usr/include/c++/11/ios:38,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/postypes.h:222:5: note: candidate: ‘template<class _StateT> bool std::operator==(const std::fpos<_StateT>&, const std::fpos<_StateT>&)’
  222 |     operator==(const fpos<_StateT>& __lhs, const fpos<_StateT>& __rhs)
      |     ^~~~~~~~
/usr/include/c++/11/bits/postypes.h:222:5: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/11/string:48,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/stl_function.h:370:20: note:   ‘const CityRecord’ is not derived from ‘const std::fpos<_StateT>’
  370 |       { return __x == __y; }
      |                ~~~~^~~~~~
In file included from /usr/include/c++/11/bits/stl_algobase.h:64,
                 from /usr/include/c++/11/bits/char_traits.h:39,
                 from /usr/include/c++/11/ios:40,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/stl_pair.h:466:5: note: candidate: ‘template<class _T1, class _T2> constexpr bool std::operator==(const std::pair<_T1, _T2>&, const std::pair<_T1, _T2>&)’
  466 |     operator==(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
      |     ^~~~~~~~
/usr/include/c++/11/bits/stl_pair.h:466:5: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/11/string:48,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/stl_function.h:370:20: note:   ‘const CityRecord’ is not derived from ‘const std::pair<_T1, _T2>’
  370 |       { return __x == __y; }
      |                ~~~~^~~~~~
In file included from /usr/include/c++/11/bits/stl_algobase.h:67,
                 from /usr/include/c++/11/bits/char_traits.h:39,
                 from /usr/include/c++/11/ios:40,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/stl_iterator.h:420:5: note: candidate: ‘template<class _Iterator> constexpr bool std::operator==(const std::reverse_iterator<_Iterator>&, const std::reverse_iterator<_Iterator>&)’
  420 |     operator==(const reverse_iterator<_Iterator>& __x,
      |     ^~~~~~~~
/usr/include/c++/11/bits/stl_iterator.h:420:5: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/11/string:48,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/stl_function.h:370:20: note:   ‘const CityRecord’ is not derived from ‘const std::reverse_iterator<_Iterator>’
  370 |       { return __x == __y; }
      |                ~~~~^~~~~~
In file included from /usr/include/c++/11/bits/stl_algobase.h:67,
                 from /usr/include/c++/11/bits/char_traits.h:39,
                 from /usr/include/c++/11/ios:40,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/stl_iterator.h:459:5: note: candidate: ‘template<class _IteratorL, class _IteratorR> constexpr bool std::operator==(const std::reverse_iterator<_Iterator>&, const std::reverse_iterator<_IteratorR>&)’
  459 |     operator==(const reverse_iterator<_IteratorL>& __x,
      |     ^~~~~~~~
/usr/include/c++/11/bits/stl_iterator.h:459:5: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/11/string:48,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/stl_function.h:370:20: note:   ‘const CityRecord’ is not derived from ‘const std::reverse_iterator<_Iterator>’
  370 |       { return __x == __y; }
      |                ~~~~^~~~~~
In file included from /usr/include/c++/11/bits/stl_algobase.h:67,
                 from /usr/include/c++/11/bits/char_traits.h:39,
                 from /usr/include/c++/11/ios:40,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/stl_iterator.h:1585:5: note: candidate: ‘template<class _IteratorL, class _IteratorR> constexpr bool std::operator==(const std::move_iterator<_IteratorL>&, const std::move_iterator<_IteratorR>&)’
 1585 |     operator==(const move_iterator<_IteratorL>& __x,
      |     ^~~~~~~~
/usr/include/c++/11/bits/stl_iterator.h:1585:5: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/11/string:48,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/stl_function.h:370:20: note:   ‘const CityRecord’ is not derived from ‘const std::move_iterator<_IteratorL>’
  370 |       { return __x == __y; }
      |                ~~~~^~~~~~
In file included from /usr/include/c++/11/bits/stl_algobase.h:67,
                 from /usr/include/c++/11/bits/char_traits.h:39,
                 from /usr/include/c++/11/ios:40,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/stl_iterator.h:1648:5: note: candidate: ‘template<class _Iterator> constexpr bool std::operator==(const std::move_iterator<_IteratorL>&, const std::move_iterator<_IteratorL>&)’
 1648 |     operator==(const move_iterator<_Iterator>& __x,
      |     ^~~~~~~~
/usr/include/c++/11/bits/stl_iterator.h:1648:5: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/11/string:48,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/stl_function.h:370:20: note:   ‘const CityRecord’ is not derived from ‘const std::move_iterator<_IteratorL>’
  370 |       { return __x == __y; }
      |                ~~~~^~~~~~
In file included from /usr/include/c++/11/string:41,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/allocator.h:218:5: note: candidate: ‘template<class _T1, class _T2> bool std::operator==(const std::allocator<_CharT>&, const std::allocator<_T2>&)’
  218 |     operator==(const allocator<_T1>&, const allocator<_T2>&)
      |     ^~~~~~~~
/usr/include/c++/11/bits/allocator.h:218:5: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/11/string:48,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/stl_function.h:370:20: note:   ‘const CityRecord’ is not derived from ‘const std::allocator<_CharT>’
  370 |       { return __x == __y; }
      |                ~~~~^~~~~~
In file included from /usr/include/c++/11/bits/basic_string.h:48,
                 from /usr/include/c++/11/string:55,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/string_view:535:5: note: candidate: ‘template<class _CharT, class _Traits> constexpr bool std::operator==(std::basic_string_view<_CharT, _Traits>, std::basic_string_view<_CharT, _Traits>)’
  535 |     operator==(basic_string_view<_CharT, _Traits> __x,
      |     ^~~~~~~~
/usr/include/c++/11/string_view:535:5: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/11/string:48,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/stl_function.h:370:20: note:   ‘CityRecord’ is not derived from ‘std::basic_string_view<_CharT, _Traits>’
  370 |       { return __x == __y; }
      |                ~~~~^~~~~~
In file included from /usr/include/c++/11/bits/basic_string.h:48,
                 from /usr/include/c++/11/string:55,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/string_view:541:5: note: candidate: ‘template<class _CharT, class _Traits> constexpr bool std::operator==(std::basic_string_view<_CharT, _Traits>, std::__type_identity_t<std::basic_string_view<_CharT, _Traits> >)’
  541 |     operator==(basic_string_view<_CharT, _Traits> __x,
      |     ^~~~~~~~
/usr/include/c++/11/string_view:541:5: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/11/string:48,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/stl_function.h:370:20: note:   ‘CityRecord’ is not derived from ‘std::basic_string_view<_CharT, _Traits>’
  370 |       { return __x == __y; }
      |                ~~~~^~~~~~
In file included from /usr/include/c++/11/bits/basic_string.h:48,
                 from /usr/include/c++/11/string:55,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/string_view:564:5: note: candidate: ‘template<class _CharT, class _Traits> constexpr bool std::operator==(std::__type_identity_t<std::basic_string_view<_CharT, _Traits> >, std::basic_string_view<_CharT, _Traits>)’
  564 |     operator==(__type_identity_t<basic_string_view<_CharT, _Traits>> __x,
      |     ^~~~~~~~
/usr/include/c++/11/string_view:564:5: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/11/string:48,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/stl_function.h:370:20: note:   ‘CityRecord’ is not derived from ‘std::basic_string_view<_CharT, _Traits>’
  370 |       { return __x == __y; }
      |                ~~~~^~~~~~
In file included from /usr/include/c++/11/string:55,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/basic_string.h:6226:5: note: candidate: ‘template<class _CharT, class _Traits, class _Alloc> bool std::operator==(const std::__cxx11::basic_string<_CharT, _Traits, _Allocator>&, const std::__cxx11::basic_string<_CharT, _Traits, _Allocator>&)’
 6226 |     operator==(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
      |     ^~~~~~~~
/usr/include/c++/11/bits/basic_string.h:6226:5: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/11/string:48,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/stl_function.h:370:20: note:   ‘const CityRecord’ is not derived from ‘const std::__cxx11::basic_string<_CharT, _Traits, _Allocator>’
  370 |       { return __x == __y; }
      |                ~~~~^~~~~~
In file included from /usr/include/c++/11/string:55,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/basic_string.h:6234:5: note: candidate: ‘template<class _CharT> typename __gnu_cxx::__enable_if<std::__is_char<_Tp>::__value, bool>::__type std::operator==(const std::__cxx11::basic_string<_CharT>&, const std::__cxx11::basic_string<_CharT>&)’
 6234 |     operator==(const basic_string<_CharT>& __lhs,
      |     ^~~~~~~~
/usr/include/c++/11/bits/basic_string.h:6234:5: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/11/string:48,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/stl_function.h:370:20: note:   ‘const CityRecord’ is not derived from ‘const std::__cxx11::basic_string<_CharT>’
  370 |       { return __x == __y; }
      |                ~~~~^~~~~~
In file included from /usr/include/c++/11/string:55,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/basic_string.h:6248:5: note: candidate: ‘template<class _CharT, class _Traits, class _Alloc> bool std::operator==(const std::__cxx11::basic_string<_CharT, _Traits, _Allocator>&, const _CharT*)’
 6248 |     operator==(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
      |     ^~~~~~~~
/usr/include/c++/11/bits/basic_string.h:6248:5: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/11/string:48,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/stl_function.h:370:20: note:   ‘const CityRecord’ is not derived from ‘const std::__cxx11::basic_string<_CharT, _Traits, _Allocator>’
  370 |       { return __x == __y; }
      |                ~~~~^~~~~~
In file included from /usr/include/c++/11/string:55,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/basic_string.h:6289:5: note: candidate: ‘template<class _CharT, class _Traits, class _Alloc> bool std::operator==(const _CharT*, const std::__cxx11::basic_string<_CharT, _Traits, _Allocator>&)’
 6289 |     operator==(const _CharT* __lhs,
      |     ^~~~~~~~
/usr/include/c++/11/bits/basic_string.h:6289:5: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/11/string:48,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/stl_function.h:370:20: note:   mismatched types ‘const _CharT*’ and ‘CityRecord’
  370 |       { return __x == __y; }
      |                ~~~~^~~~~~
In file included from /usr/include/c++/11/bits/locale_facets.h:48,
                 from /usr/include/c++/11/bits/basic_ios.h:37,
                 from /usr/include/c++/11/ios:44,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/streambuf_iterator.h:226:5: note: candidate: ‘template<class _CharT, class _Traits> bool std::operator==(const std::istreambuf_iterator<_CharT, _Traits>&, const std::istreambuf_iterator<_CharT, _Traits>&)’
  226 |     operator==(const istreambuf_iterator<_CharT, _Traits>& __a,
      |     ^~~~~~~~
/usr/include/c++/11/bits/streambuf_iterator.h:226:5: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/11/string:48,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/stl_function.h:370:20: note:   ‘const CityRecord’ is not derived from ‘const std::istreambuf_iterator<_CharT, _Traits>’
  370 |       { return __x == __y; }
      |                ~~~~^~~~~~
In file included from /usr/include/c++/11/vector:67,
                 from main.cpp:7:
/usr/include/c++/11/bits/stl_vector.h:1892:5: note: candidate: ‘template<class _Tp, class _Alloc> bool std::operator==(const std::vector<_Tp, _Alloc>&, const std::vector<_Tp, _Alloc>&)’
 1892 |     operator==(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y)
      |     ^~~~~~~~
/usr/include/c++/11/bits/stl_vector.h:1892:5: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/11/string:48,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/stl_function.h:370:20: note:   ‘const CityRecord’ is not derived from ‘const std::vector<_Tp, _Alloc>’
  370 |       { return __x == __y; }
      |                ~~~~^~~~~~
In file included from /usr/include/c++/11/tuple:39,
                 from /usr/include/c++/11/bits/hashtable_policy.h:34,
                 from /usr/include/c++/11/bits/hashtable.h:35,
                 from /usr/include/c++/11/unordered_map:46,
                 from main.cpp:8:
/usr/include/c++/11/array:276:5: note: candidate: ‘template<class _Tp, long unsigned int _Nm> bool std::operator==(const std::array<_Tp, _Nm>&, const std::array<_Tp, _Nm>&)’
  276 |     operator==(const array<_Tp, _Nm>& __one, const array<_Tp, _Nm>& __two)
      |     ^~~~~~~~
/usr/include/c++/11/array:276:5: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/11/string:48,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/stl_function.h:370:20: note:   ‘const CityRecord’ is not derived from ‘const std::array<_Tp, _Nm>’
  370 |       { return __x == __y; }
      |                ~~~~^~~~~~
In file included from /usr/include/c++/11/bits/hashtable_policy.h:34,
                 from /usr/include/c++/11/bits/hashtable.h:35,
                 from /usr/include/c++/11/unordered_map:46,
                 from main.cpp:8:
/usr/include/c++/11/tuple:1524:5: note: candidate: ‘template<class ... _TElements, class ... _UElements> constexpr bool std::operator==(const std::tuple<_Tps ...>&, const std::tuple<_UTypes ...>&)’
 1524 |     operator==(const tuple<_TElements...>& __t,
      |     ^~~~~~~~
/usr/include/c++/11/tuple:1524:5: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/11/string:48,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/stl_function.h:370:20: note:   ‘const CityRecord’ is not derived from ‘const std::tuple<_Tps ...>’
  370 |       { return __x == __y; }
      |                ~~~~^~~~~~
In file included from /usr/include/c++/11/unordered_map:47,
                 from main.cpp:8:
/usr/include/c++/11/bits/unordered_map.h:2134:5: note: candidate: ‘template<class _Key1, class _Tp1, class _Hash1, class _Pred1, class _Alloc1> bool std::operator==(const std::unordered_map<_Key1, _Tp1, _Hash1, _Pred1, _Alloc1>&, const std::unordered_map<_Key1, _Tp1, _Hash1, _Pred1, _Alloc1>&)’
 2134 |     operator==(const unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>& __x,
      |     ^~~~~~~~
/usr/include/c++/11/bits/unordered_map.h:2134:5: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/11/string:48,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/stl_function.h:370:20: note:   ‘const CityRecord’ is not derived from ‘const std::unordered_map<_Key1, _Tp1, _Hash1, _Pred1, _Alloc1>’
  370 |       { return __x == __y; }
      |                ~~~~^~~~~~
In file included from /usr/include/c++/11/unordered_map:47,
                 from main.cpp:8:
/usr/include/c++/11/bits/unordered_map.h:2148:5: note: candidate: ‘template<class _Key1, class _Tp1, class _Hash1, class _Pred1, class _Alloc1> bool std::operator==(const std::unordered_multimap<_Key1, _Tp1, _Hash1, _Pred1, _Alloc1>&, const std::unordered_multimap<_Key1, _Tp1, _Hash1, _Pred1, _Alloc1>&)’
 2148 |     operator==(const unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc>& __x,
      |     ^~~~~~~~
/usr/include/c++/11/bits/unordered_map.h:2148:5: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/11/string:48,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/stl_function.h:370:20: note:   ‘const CityRecord’ is not derived from ‘const std::unordered_multimap<_Key1, _Tp1, _Hash1, _Pred1, _Alloc1>’
  370 |       { return __x == __y; }
      |                ~~~~^~~~~~
In file included from /usr/include/c++/11/map:61,
                 from main.cpp:9:
/usr/include/c++/11/bits/stl_map.h:1463:5: note: candidate: ‘template<class _Key, class _Tp, class _Compare, class _Alloc> bool std::operator==(const std::map<_Key, _Tp, _Compare, _Allocator>&, const std::map<_Key, _Tp, _Compare, _Allocator>&)’
 1463 |     operator==(const map<_Key, _Tp, _Compare, _Alloc>& __x,
      |     ^~~~~~~~
/usr/include/c++/11/bits/stl_map.h:1463:5: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/11/string:48,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/stl_function.h:370:20: note:   ‘const CityRecord’ is not derived from ‘const std::map<_Key, _Tp, _Compare, _Allocator>’
  370 |       { return __x == __y; }
      |                ~~~~^~~~~~
In file included from /usr/include/c++/11/map:62,
                 from main.cpp:9:
/usr/include/c++/11/bits/stl_multimap.h:1128:5: note: candidate: ‘template<class _Key, class _Tp, class _Compare, class _Alloc> bool std::operator==(const std::multimap<_Key, _Tp, _Compare, _Allocator>&, const std::multimap<_Key, _Tp, _Compare, _Allocator>&)’
 1128 |     operator==(const multimap<_Key, _Tp, _Compare, _Alloc>& __x,
      |     ^~~~~~~~
/usr/include/c++/11/bits/stl_multimap.h:1128:5: note:   template argument deduction/substitution failed:
In file included from /usr/include/c++/11/string:48,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/bits/stl_function.h:370:20: note:   ‘const CityRecord’ is not derived from ‘const std::multimap<_Key, _Tp, _Compare, _Allocator>’
  370 |       { return __x == __y; }
      |                ~~~~^~~~~~
In file included from /usr/include/c++/11/bits/ios_base.h:46,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from main.cpp:3:
/usr/include/c++/11/system_error:362:3: note: candidate: ‘bool std::operator==(const std::error_code&, const std::error_code&)’
  362 |   operator==(const error_code& __lhs, const error_code& __rhs) noexcept
      |   ^~~~~~~~
/usr/include/c++/11/system_error:362:32: note:   no known conversion for argument 1 from ‘const CityRecord’ to ‘const std::error_code&’
  362 |   operator==(const error_code& __lhs, const error_code& __rhs) noexcept
      |              ~~~~~~~~~~~~~~~~~~^~~~~
/usr/include/c++/11/system_error:368:3: note: candidate: ‘bool std::operator==(const std::error_code&, const std::error_condition&)’
  368 |   operator==(const error_code& __lhs, const error_condition& __rhs) noexcept
      |   ^~~~~~~~
/usr/include/c++/11/system_error:368:32: note:   no known conversion for argument 1 from ‘const CityRecord’ to ‘const std::error_code&’
  368 |   operator==(const error_code& __lhs, const error_condition& __rhs) noexcept
      |              ~~~~~~~~~~~~~~~~~~^~~~~
/usr/include/c++/11/system_error:376:3: note: candidate: ‘bool std::operator==(const std::error_condition&, const std::error_condition&)’
  376 |   operator==(const error_condition& __lhs,
      |   ^~~~~~~~
/usr/include/c++/11/system_error:376:37: note:   no known conversion for argument 1 from ‘const CityRecord’ to ‘const std::error_condition&’
  376 |   operator==(const error_condition& __lhs,
      |              ~~~~~~~~~~~~~~~~~~~~~~~^~~~~
/usr/include/c++/11/system_error:408:3: note: candidate: ‘bool std::operator==(const std::error_condition&, const std::error_code&)’
  408 |   operator==(const error_condition& __lhs, const error_code& __rhs) noexcept
      |   ^~~~~~~~
/usr/include/c++/11/system_error:408:37: note:   no known conversion for argument 1 from ‘const CityRecord’ to ‘const std::error_condition&’
  408 |   operator==(const error_condition& __lhs, const error_code& __rhs) noexcept
      |              ~~~~~~~~~~~~~~~~~~~~~~~^~~~~
    
    
    */


    return 0;
}