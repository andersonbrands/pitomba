
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
            static const EventId CREATE_D3D_VERTEX_BUFFER = 5;
            static const EventId CREATE_D3D_TEXTURE = 6;
            static const EventId RENDER_TEXTURE = 7;
            static const EventId SETUP_VIEW_MATRIX = 8;
            static const EventId SETUP_LH_ORTHOGONAL_PROJECTION_MATRIX = 9;

        }
    }
}

#endif // EVENT_ID_H_
