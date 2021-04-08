
#include "Kernel.h"
#include "..\Utils\Logger.h"


namespace pitomba {

    Kernel::Kernel() {}

    Kernel::~Kernel() {}

    void Kernel::execute() {
        Logger logger;

        logger.debug("Kernel executing");
    }

}