# Create the extension library

SET( EXTENSION_NAME "Extensions_BagContainer")

ADD_LIBRARY( ${EXTENSION_NAME}
	dummy.cpp
	Util\Bag.h
)

