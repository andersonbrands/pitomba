
#ifndef EVENT_ID_H_
#define EVENT_ID_H_

namespace pitomba {

    using EventId = unsigned int;
    namespace ev {

        namespace id {

            static const EventId DUMMY_EVENT = 0;
            static const EventId APPLICATION_QUIT = 1;
            static const EventId PRE_RENDER = 2;
            static const EventId RENDER = 3;
            static const EventId POST_RENDER = 4;
            static const EventId INPUT_UPDATED = 5;

        }
    }
}

#endif // EVENT_ID_H_
