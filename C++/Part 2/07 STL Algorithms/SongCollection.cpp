/*
Name: Yongtak Jun
Email: yjun4@myseneca.ca
Date: Mar/20/2021
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "SongCollection.h"

namespace sdds
{
	void SongCollection::trim(string& str)const
	{
		size_t i = 0;


		//removing leading spaces
		for (i = 0; i < str.length() && str[i] == ' '; i++);
		str = str.substr(i);


		//removing trailing spaces
		for (i = str.length(); i > 0 && str[i - 1] == ' '; i--);
		str = str.substr(0, i);
	}

	SongCollection::SongCollection() {}

	SongCollection::SongCollection(const char* file)
	{
		if (file == nullptr || file[0] == '\0')
			throw "The filename is incorrect.";
		else
		{
			ifstream f(file);
			while (f)
			{
				Song tempSong{};
				
				tempSong.m_title.resize(25);
				f.read(&(tempSong.m_title[0]), 25);
				trim(tempSong.m_title);

				tempSong.m_artist.resize(25);
				f.read(&(tempSong.m_artist[0]), 25);
				trim(tempSong.m_artist);

				tempSong.m_album.resize(25);
				f.read(&(tempSong.m_album[0]), 25);
				trim(tempSong.m_album);

				tempSong.m_releaseYear.resize(5);
				f.read(&(tempSong.m_releaseYear[0]), 5);
				trim(tempSong.m_releaseYear);

				string tempLength(5, '\0'); //creating 'tempLength' string object with size 5 filled with '\0'
				f.read(&(tempLength[0]), 5);
				tempSong.m_length = stoi(tempLength);

				string tempPrice(5, '\0');
				f.read(&(tempPrice[0]), 5);
				tempSong.m_price = stod(tempPrice);

				collection.push_back(tempSong);

				f.get(); //to get record terminator, and to set up eofbit to true when the file reaches the end
			}
			f.close();
		}
	}

	void SongCollection::display(std::ostream& out) const
	{
		for_each(collection.begin(), collection.end(), [&](Song theSong) {out << theSong << endl; });

		size_t totalPlaytime = accumulate(collection.begin(), collection.end(), (int)0, [](size_t x, Song theSong) {return x + theSong.m_length; });

		size_t hours = totalPlaytime / 3600;
		size_t minutes = (totalPlaytime % 3600) / 60;
		size_t seconds = (totalPlaytime % 3600) % 60;

		out << "----------------------------------------------------------------------------------------" << endl;
		out << "|                                                        Total Listening Time: " << hours << ":" << minutes << ":" << seconds << " |" << endl;

	}

	void SongCollection::sort(const char* sorting)
	{
		if (strcmp(sorting, "title") == 0)
		{
			std::sort(collection.begin(), collection.end(), [](const Song one, const Song two) {return one.m_title < two.m_title; });
		}
		else if (strcmp(sorting, "album") == 0)
		{
			std::sort(collection.begin(), collection.end(), [](const Song one, const Song two) {return one.m_album < two.m_album; });
		}
		else if (strcmp(sorting, "length") == 0)
		{
			std::sort(collection.begin(), collection.end(), [](const Song one, const Song two) {return one.m_length < two.m_length; });
		}
	}


	void SongCollection::cleanAlbum()
	{
		transform(collection.begin(), collection.end(), collection.begin(),
			[](Song theSong)
			{
			if (theSong.m_album == "[None]")
				theSong.m_album = "";

			return theSong;
			}
		);
	}

	bool SongCollection::inCollection(const char* artist) const
	{
		return any_of(collection.begin(), collection.end(), [=](const Song theSong) {return theSong.m_artist == artist; });
	}

	std::list<Song> SongCollection::getSongsForArtist(const char* artist) const
	{
		int numOfList = count_if(collection.begin(), collection.end(), [=](const Song theSong) {return theSong.m_artist == artist; });

		list<Song> byArtist(numOfList);
		copy_if(collection.begin(), collection.end(), byArtist.begin(), [=](const Song theSong) {return theSong.m_artist == artist; });
		
		return byArtist;
	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong)
	{
		size_t minutes = theSong.m_length / 60;
		size_t seconds = theSong.m_length % 60;


		out << "| " << left << setw(20) << theSong.m_title << " | " << setw(15) << theSong.m_artist << " | " << setw(20) << theSong.m_album << " | " << right << setw(6) << theSong.m_releaseYear << " | " << minutes << ":" << setfill('0') << setw(2) << seconds << setfill(' ') << " | " << theSong.m_price << " |";

		return out;
	}

}