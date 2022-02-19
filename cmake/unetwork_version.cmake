# UNETWORK_BUILD_DEFINE: UNETWORK_VERSION_MAJOR, lib major version number, type=int, group=unetwork_base
# UNETWORK_CONFIG: UNETWORK_VERSION_MAJOR, lib major version number, type=int, group=unetwork_base
set(UNETWORK_VERSION_MAJOR 0)
# UNETWORK_BUILD_DEFINE: UNETWORK_VERSION_MINOR, lib minor version number, type=int, group=unetwork_base
# UNETWORK_CONFIG: UNETWORK_VERSION_MINOR, lib minor version number, type=int, group=unetwork_base
set(UNETWORK_VERSION_MINOR 0)
# UNETWORK_BUILD_DEFINE: UNETWORK_VERSION_REVISION, lib version revision, type=int, group=unetwork_base
# UNETWORK_CONFIG: UNETWORK_VERSION_REVISION, lib version revision, type=int, group=unetwork_base
set(UNETWORK_VERSION_REVISION 1)
# UNETWORK_BUILD_DEFINE: UNETWORK_VERSION_PRE_RELEASE_ID, optional lib pre-release version identifier, type=string, group=unetwork_base
# UNETWORK_CONFIG: UNETWORK_VERSION_PRE_RELEASE_ID, optional lib pre-release version identifier, type=string, group=unetwork_base
#set(UNETWORK_VERSION_PRE_RELEASE_ID develop)

# UNETWORK_BUILD_DEFINE: UNETWORK_VERSION_STRING, lib version, type=string, group=unetwork_base
# UNETWORK_CONFIG: UNETWORK_VERSION_STRING, lib version, type=string, group=unetwork_base
set(UNETWORK_VERSION_STRING "${UNETWORK_VERSION_MAJOR}.${UNETWORK_VERSION_MINOR}.${UNETWORK_VERSION_REVISION}")

if (UNETWORK_VERSION_PRE_RELEASE_ID)
    set(UNETWORK_VERSION_STRING "${UNETWORK_VERSION_STRING}-${UNETWORK_VERSION_PRE_RELEASE_ID}")
endif()