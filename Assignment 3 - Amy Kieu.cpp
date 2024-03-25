#include <iostream>
#include <vector>
#include <iomanip> // for std::hex
#include <ctime>
#include <cstdlib>

// declare variables
const int page_size = 1024;
const int frame_size = 1024;
const int num_pages = 16;
const int num_frames = 6;


// function to generate random logical address
int generate_logical_address() {
	return rand() % (num_pages * page_size);
}

// function to handle page faults by storing in secondary storage, and loading into memory when needed
void page_faults(int page_num, std::vector<int>& page_frame_table, std::vector<bool>& physical_memory) {
	for (int i = 0; i < num_frames; ++i) { // search for empty frame in seconday memory
		if (!physical_memory[i]) { // if physical memory not occupied by a page
			page_frame_table[page_num] = i; // load into empty frame
			physical_memory[i] = true; // update to indicate frame being used
			std::cout << "Page Number: 0x" << std::hex << std::uppercase << page_num << " loaded into frame " << i << std::endl;
			std::cout << std::endl;
			return;
		}
	}
	std::cout << "No available frames in memory. Unable to load page" << std::endl;
	std::cout<<std::endl;
}

int main() {
	srand(time(nullptr)); // Seed random number generator with current time

	// Data structure for page/frame table
	std::vector <int> page_frame_table(num_pages, -1); // initially not mapped 
	std::vector <bool> physical_memory(num_frames, false); // initially empty frames, track frame usage

	// function to translate logical address to physical address, and providing the page numbers and offset
	for (int i = 0; i < 5; ++i) {
		int logical_address = generate_logical_address(); // call the logical address generator function
		int page_num = logical_address / page_size; // get the page num
		int offset = logical_address % page_size; // get the offset within page

		if (page_num >= num_pages) { // case for invalid page numbers
			std::cout << "Logical Address: 0x" << std::hex << logical_address
				<< " => Invalid Page Number: 0x" << page_num << std::endl;
			continue;
		}

		int frameNumber = page_frame_table[page_num]; // get frame number corresponding to page num
		if (frameNumber == -1) { // check if page is loaded in memory
			page_faults(page_num, page_frame_table, physical_memory); // load page into memory
			frameNumber = page_frame_table[page_num]; // get frame number again after handling the page fault
			if (frameNumber == -1) { // page not loaded in memory
				std::cout << "Unable to load page into memory" << std::endl;
				continue;
			}
		}

		int physical_address = frameNumber * frame_size + offset; // get physical adress

		// print logical address, page number, and offset
		if (logical_address != physical_address) {
			std::cout << "Logical Address: 0x" << std::hex << std::uppercase << logical_address
				<< " => Physical Address: 0x" << std::hex << std::uppercase << physical_address
				<< ", Page Number: 0x" << std::hex << std::uppercase << page_num
				<< ", Offset: 0x" << std::hex << std::uppercase << offset << std::endl;
			std::cout << std::endl;
		}
	}
	return 0;
}
