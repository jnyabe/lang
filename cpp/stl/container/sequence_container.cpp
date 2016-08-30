#include <sstream>
#include "sequence_container.h"

void SequenceContainer::start(ElapsedTime& etime) const
{
	etime.start = std::chrono::system_clock::now();
}
void SequenceContainer::end(ElapsedTime& etime) const
{
	etime.end = std::chrono::system_clock::now();
}

std::string SequenceContainer::format(const ElapsedTime& etime) const
{
	std::ostringstream sout;
	auto diff = etime.end - etime.start;
	sout << "Elapsed time: "
		 << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
	
	return sout.str();
}
