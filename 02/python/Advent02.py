
input = "1090286-1131879,3259566-3404881,138124-175118,266204727-266361099,16765-24272,7657360692-7657593676,88857504-88926597,6869078-6903096,48444999-48532270,61427792-61580535,71-103,8077-10421,1920-2560,2-17,951-1259,34-50,28994-36978,1309-1822,9393918461-9393960770,89479-120899,834641-988077,5389718924-5389797353,34010076-34214499,5063-7100,607034-753348,19098586-19261191,125085556-125188689,39839-51927,3246-5037,174-260,439715-473176,187287-262190,348-535,58956-78301,4388160-4505757,512092-584994,13388753-13534387"
#input = "11-22,95-115,998-1012,1188511880-1188511890,222220-222224,1698522-1698528,446443-446449,38593856-38593862,565653-565659,824824821-824824827,2121212118-2121212124"
big_array = input.split(",")
i = 0
array = []
for entry in big_array:
    array.append(big_array[i].split("-"))
    i += 1

found_invalid_ids_part1 = []
found_invalid_ids_part2 = []

for duo in array:
    for x in range(int(duo[0]), int(duo[1])+1):
        string_number = str(x)
        string_part1 = string_number[:len(string_number)//2]
        string_part2 = string_number[len(string_number)//2:]
        
        if (string_part1 == string_part2):
            found_invalid_ids_part1.append(x)

        for length_sequence in range(1,(len(string_number)//2)+1):
            #print("Length: " + str(length_sequence) + ", Number: " + string_number)
            #print("CompareNum: " + string_number[:length_sequence])
            compare_num = string_number[:length_sequence]
            #print(string_number.split(compare_num))
            split_array = string_number.split(compare_num)
            if (set(split_array) == {''}):
                found_invalid_ids_part2.append(x)
                break
                #print("INVALID: " + str(x))

print(found_invalid_ids_part2)

# Count together
total_part1 = 0
for num in found_invalid_ids_part1:
    total_part1 += num
print("TOTAL Part1: " + str(total_part1))

total_part2 = 0
for num in found_invalid_ids_part2:
    total_part2 += num
print("TOTAL Part2: " + str(total_part2))