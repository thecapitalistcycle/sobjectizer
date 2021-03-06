/*
	SObjectizer 5.
*/

#include <so_5/event_exception_logger.hpp>

#include <iostream>

namespace so_5
{

//
// event_exception_logger_t
//

void
event_exception_logger_t::on_install(
	event_exception_logger_unique_ptr_t previous_logger ) noexcept
{
	// Default implementation deletes old logger.
	previous_logger.reset();
}

namespace /* ananymous */
{

//
// std_event_exception_logger_t
//

//! Standard exception logger implementation.
class std_event_exception_logger_t
	:
		public event_exception_logger_t
{
	public:
		std_event_exception_logger_t() = default;

		void
		log_exception(
			const std::exception & event_exception,
			const coop_handle_t & coop ) noexcept override
		{
			std::cerr
				<< "SObjectizer event exception caught: "
				<< event_exception.what()
				<< "; cooperation: " << coop << std::endl;
		}
};

} /* anonymous namespace */

//
// create_std_event_exception_logger
//

SO_5_FUNC event_exception_logger_unique_ptr_t
create_std_event_exception_logger()
{
	return event_exception_logger_unique_ptr_t(
		new std_event_exception_logger_t() );
}

} /* namespace so_5 */
