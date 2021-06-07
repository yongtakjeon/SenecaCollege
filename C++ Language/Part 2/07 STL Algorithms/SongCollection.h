/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Mar/20/2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cstring>

using namespace std;

namespace sdds
{
	struct Song
	{
		string m_artist{};
		string m_title{};
		string m_album{};
		string m_releaseYear{};
		double m_price{};
		size_t m_length{};
	};

	class SongCollection
	{
		vector<Song> collection{};
		void trim(string& str)const;
	public:
		SongCollection();
		SongCollection(const char* file);
		void display(std::ostream& out) const;
		void sort(const char* sorting);
		void cleanAlbum();
		bool inCollection(const char* artist) const;
		std::list<Song> getSongsForArtist(const char* artist) const;

	};

	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif // !SDDS_SONGCOLLECTION_H
