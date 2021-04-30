
#ifndef EVENT_ID_H_
#define EVENT_ID_H_

namespace pitomba {

    using EventId = unsigned int;
    namespace ev {

        namespace id {

            static const EventId DUMMY_EVENT = 0;
            static const EventId APPLICATION_QUIT = 1;

        }
    }
}

#endif // EVENT_ID_H_
