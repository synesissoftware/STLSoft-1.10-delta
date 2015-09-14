/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.winstl.error.error_functions.cpp
 *
 * Purpose:     Implementation file for the test.unit.winstl.error.error_functions project.
 *
 * Created:     8th April 2014
 * Updated:     8th April 2014
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2014, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <winstl/error/error_functions.h>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xCover Header Files */
#ifdef STLSOFT_USE_XCOVER
# include <xcover/xcover.h>
#endif /* STLSOFT_USE_XCOVER */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <winstl/dl/module.hpp>
#include <stlsoft/conversion/char_conversions.hpp>
#include <stlsoft/conversion/integer_to_string.hpp>
#include <stlsoft/smartptr/scoped_handle.hpp>

/* Standard C++ Header Files */
#include <string>
#include <vector>

/* Standard C Header Files */
#include <errno.h>
#include <stdlib.h>
#include <string.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_winstl_C_format_message_strerror_a(void);
    static void test_format_message_multibyte(void);
    static void test_format_message_wide(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Encoding
 */

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.winstl.error.error_functions", verbosity))
    {
		XTESTS_RUN_CASE(test_winstl_C_format_message_strerror_a);
        XTESTS_RUN_CASE(test_format_message_multibyte);
        XTESTS_RUN_CASE(test_format_message_wide);

#ifdef STLSOFT_USE_XCOVER
        XCOVER_REPORT_FILE_COVERAGE("*winstl/*/error_functions.hpp", NULL);
#endif /* STLSOFT_USE_XCOVER */

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * Test function implementations
 */

namespace
{

    static std::string lookup_error_or_number_a(int code, bool convertToNumber = true)
    {
		DWORD	flags	=	0;
		LPSTR	buff;

		flags |= FORMAT_MESSAGE_ALLOCATE_BUFFER;
//		flags |= FORMAT_MESSAGE_IGNORE_INSERTS;
		flags |= FORMAT_MESSAGE_FROM_SYSTEM;

		DWORD	r = ::FormatMessageA(
			flags
		,	NULL
		,	code
		,	MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT)
		,	(LPSTR)&buff
		,	0
		,	NULL
		);

		if( 0 == r &&
			convertToNumber)
		{
			char	sz[21];

			return std::string(stlsoft::integer_to_string(sz, STLSOFT_NUM_ELEMENTS(sz), code));
		}
		else
		{
			std::string s(buff, r);

			::LocalFree(buff);

			for(;!s.empty();)
			{
				switch(s[s.size() - 1])
				{
					case	'.':
						if(s.size() - 1 == s.find('.'))
						{
					case	' ':
					case	'\t':
					case	'\r':
					case	'\n':
						s.resize(s.size() - 1);
						break;
						}
						else
						{
					default:
						return s;
						}
				}
			}

			return s;
		}
    }

    static std::string lookup_error_a(int code)
    {
		return lookup_error_or_number_a(code, false);
	}

    static std::wstring lookup_error_or_number_w(int code)
    {
        return stlsoft::m2w(lookup_error_or_number_a(code, true).c_str()).c_str();
    }

    static std::wstring lookup_error_w(int code)
    {
        return stlsoft::m2w(lookup_error_or_number_a(code, false).c_str()).c_str();
	}

#ifdef UNICODE
# define lookup_error_or_number	lookup_error_or_number_w
# define lookup_error			lookup_error_w
#else /* ? UNICODE */
# define lookup_error_or_number	lookup_error_or_number_a
# define lookup_error			lookup_error_a
#endif /* UNICODE */


    static DWORD code_no_inserts[] = 
    {
        ERROR_SUCCESS,
        ERROR_INVALID_FUNCTION,
        ERROR_FILE_NOT_FOUND,
        ERROR_PATH_NOT_FOUND,
        ERROR_TOO_MANY_OPEN_FILES,
        ERROR_ACCESS_DENIED,
        ERROR_INVALID_HANDLE,
        ERROR_ARENA_TRASHED,
        ERROR_NOT_ENOUGH_MEMORY,
        ERROR_INVALID_BLOCK,
        ERROR_BAD_ENVIRONMENT,
        ERROR_BAD_FORMAT,
        ERROR_INVALID_ACCESS,
        ERROR_INVALID_DATA,
        ERROR_OUTOFMEMORY,
        ERROR_INVALID_DRIVE,
        ERROR_CURRENT_DIRECTORY,
        ERROR_NOT_SAME_DEVICE,
        ERROR_NO_MORE_FILES,
        ERROR_WRITE_PROTECT,
        ERROR_BAD_UNIT,
        ERROR_NOT_READY,
        ERROR_BAD_COMMAND,
        ERROR_CRC,
        ERROR_BAD_LENGTH,
        ERROR_SEEK,
        ERROR_NOT_DOS_DISK,
        ERROR_SECTOR_NOT_FOUND,
        ERROR_OUT_OF_PAPER,
        ERROR_WRITE_FAULT,
        ERROR_READ_FAULT,
        ERROR_GEN_FAILURE,
        ERROR_SHARING_VIOLATION,
        ERROR_LOCK_VIOLATION,
        ERROR_SHARING_BUFFER_EXCEEDED,
        ERROR_HANDLE_EOF,
        ERROR_HANDLE_DISK_FULL,
        ERROR_NOT_SUPPORTED,
        ERROR_REM_NOT_LIST,
        ERROR_DUP_NAME,
        ERROR_BAD_NETPATH,
        ERROR_NETWORK_BUSY,
        ERROR_DEV_NOT_EXIST,
        ERROR_TOO_MANY_CMDS,
        ERROR_ADAP_HDW_ERR,
        ERROR_BAD_NET_RESP,
        ERROR_UNEXP_NET_ERR,
        ERROR_BAD_REM_ADAP,
        ERROR_PRINTQ_FULL,
        ERROR_NO_SPOOL_SPACE,
        ERROR_PRINT_CANCELLED,
        ERROR_NETNAME_DELETED,
        ERROR_NETWORK_ACCESS_DENIED,
        ERROR_BAD_DEV_TYPE,
        ERROR_BAD_NET_NAME,
        ERROR_TOO_MANY_NAMES,
        ERROR_TOO_MANY_SESS,
        ERROR_SHARING_PAUSED,
        ERROR_REQ_NOT_ACCEP,
        ERROR_REDIR_PAUSED,
        ERROR_FILE_EXISTS,
        ERROR_CANNOT_MAKE,
        ERROR_FAIL_I24,
        ERROR_OUT_OF_STRUCTURES,
        ERROR_ALREADY_ASSIGNED,
        ERROR_INVALID_PASSWORD,
        ERROR_INVALID_PARAMETER,
        ERROR_NET_WRITE_FAULT,
        ERROR_NO_PROC_SLOTS,
        ERROR_TOO_MANY_SEMAPHORES,
        ERROR_EXCL_SEM_ALREADY_OWNED,
        ERROR_SEM_IS_SET,
        ERROR_TOO_MANY_SEM_REQUESTS,
        ERROR_INVALID_AT_INTERRUPT_TIME,
        ERROR_SEM_OWNER_DIED,
        ERROR_DISK_CHANGE,
        ERROR_DRIVE_LOCKED,
        ERROR_BROKEN_PIPE,
        ERROR_OPEN_FAILED,
        ERROR_BUFFER_OVERFLOW,
        ERROR_DISK_FULL,
        ERROR_NO_MORE_SEARCH_HANDLES,
        ERROR_INVALID_TARGET_HANDLE,
        ERROR_INVALID_CATEGORY,
        ERROR_INVALID_VERIFY_SWITCH,
        ERROR_BAD_DRIVER_LEVEL,
        ERROR_CALL_NOT_IMPLEMENTED,
        ERROR_SEM_TIMEOUT,
        ERROR_INSUFFICIENT_BUFFER,
        ERROR_INVALID_NAME,
        ERROR_INVALID_LEVEL,
        ERROR_NO_VOLUME_LABEL,
        ERROR_MOD_NOT_FOUND,
        ERROR_PROC_NOT_FOUND,
        ERROR_WAIT_NO_CHILDREN,
        ERROR_DIRECT_ACCESS_HANDLE,
        ERROR_NEGATIVE_SEEK,
        ERROR_SEEK_ON_DEVICE,
        ERROR_IS_JOIN_TARGET,
        ERROR_IS_JOINED,
        ERROR_IS_SUBSTED,
        ERROR_NOT_JOINED,
        ERROR_NOT_SUBSTED,
        ERROR_JOIN_TO_JOIN,
        ERROR_SUBST_TO_SUBST,
        ERROR_JOIN_TO_SUBST,
        ERROR_SUBST_TO_JOIN,
        ERROR_BUSY_DRIVE,
        ERROR_SAME_DRIVE,
        ERROR_DIR_NOT_ROOT,
        ERROR_DIR_NOT_EMPTY,
        ERROR_IS_SUBST_PATH,
        ERROR_IS_JOIN_PATH,
        ERROR_PATH_BUSY,
        ERROR_IS_SUBST_TARGET,
        ERROR_SYSTEM_TRACE,
        ERROR_INVALID_EVENT_COUNT,
        ERROR_TOO_MANY_MUXWAITERS,
        ERROR_INVALID_LIST_FORMAT,
        ERROR_LABEL_TOO_LONG,
        ERROR_TOO_MANY_TCBS,
        ERROR_SIGNAL_REFUSED,
        ERROR_DISCARDED,
        ERROR_NOT_LOCKED,
        ERROR_BAD_THREADID_ADDR,
        ERROR_BAD_ARGUMENTS,
        ERROR_BAD_PATHNAME,
        ERROR_SIGNAL_PENDING,
        ERROR_MAX_THRDS_REACHED,
        ERROR_LOCK_FAILED,
        ERROR_BUSY,
        ERROR_CANCEL_VIOLATION,
        ERROR_ATOMIC_LOCKS_NOT_SUPPORTED,
        ERROR_INVALID_SEGMENT_NUMBER,
        ERROR_ALREADY_EXISTS,
        ERROR_INVALID_FLAG_NUMBER,
        ERROR_SEM_NOT_FOUND,
        ERROR_DYNLINK_FROM_INVALID_RING,
        ERROR_IOPL_NOT_ENABLED,
        ERROR_AUTODATASEG_EXCEEDS_64k,
        ERROR_RING2SEG_MUST_BE_MOVABLE,
        ERROR_ENVVAR_NOT_FOUND,
        ERROR_NO_SIGNAL_SENT,
        ERROR_FILENAME_EXCED_RANGE,
        ERROR_RING2_STACK_IN_USE,
        ERROR_META_EXPANSION_TOO_LONG,
        ERROR_INVALID_SIGNAL_NUMBER,
        ERROR_THREAD_1_INACTIVE,
        ERROR_LOCKED,
        ERROR_TOO_MANY_MODULES,
        ERROR_NESTING_NOT_ALLOWED,
        ERROR_BAD_PIPE,
        ERROR_PIPE_BUSY,
        ERROR_NO_DATA,
        ERROR_PIPE_NOT_CONNECTED,
        ERROR_MORE_DATA,
        ERROR_VC_DISCONNECTED,
        ERROR_INVALID_EA_NAME,
        ERROR_EA_LIST_INCONSISTENT,
        ERROR_NO_MORE_ITEMS,
        ERROR_CANNOT_COPY,
        ERROR_DIRECTORY,
        ERROR_EAS_DIDNT_FIT,
        ERROR_EA_FILE_CORRUPT,
        ERROR_EA_TABLE_FULL,
        ERROR_INVALID_EA_HANDLE,
        ERROR_EAS_NOT_SUPPORTED,
        ERROR_NOT_OWNER,
        ERROR_TOO_MANY_POSTS,
        ERROR_PARTIAL_COPY,
        ERROR_OPLOCK_NOT_GRANTED,
        ERROR_INVALID_OPLOCK_PROTOCOL,
        ERROR_INVALID_ADDRESS,
        ERROR_ARITHMETIC_OVERFLOW,
        ERROR_PIPE_CONNECTED,
        ERROR_PIPE_LISTENING,
        ERROR_EA_ACCESS_DENIED,
        ERROR_OPERATION_ABORTED,
        ERROR_IO_INCOMPLETE,
        ERROR_IO_PENDING,
        ERROR_NOACCESS,
        ERROR_SWAPERROR,
        ERROR_STACK_OVERFLOW,
        ERROR_INVALID_MESSAGE,
        ERROR_CAN_NOT_COMPLETE,
        ERROR_INVALID_FLAGS,
        ERROR_UNRECOGNIZED_VOLUME,
        ERROR_FILE_INVALID,
        ERROR_FULLSCREEN_MODE,
        ERROR_NO_TOKEN,
        ERROR_BADDB,
        ERROR_BADKEY,
        ERROR_CANTOPEN,
        ERROR_CANTREAD,
        ERROR_CANTWRITE,
        ERROR_REGISTRY_RECOVERED,
        ERROR_REGISTRY_CORRUPT,
        ERROR_REGISTRY_IO_FAILED,
        ERROR_NOT_REGISTRY_FILE,
        ERROR_KEY_DELETED,
        ERROR_NO_LOG_SPACE,
        ERROR_KEY_HAS_CHILDREN,
        ERROR_CHILD_MUST_BE_VOLATILE,
        ERROR_NOTIFY_ENUM_DIR,
        ERROR_DEPENDENT_SERVICES_RUNNING,
        ERROR_INVALID_SERVICE_CONTROL,
        ERROR_SERVICE_REQUEST_TIMEOUT,
        ERROR_SERVICE_NO_THREAD,
        ERROR_SERVICE_DATABASE_LOCKED,
        ERROR_SERVICE_ALREADY_RUNNING,
        ERROR_INVALID_SERVICE_ACCOUNT,
        ERROR_SERVICE_DISABLED,
        ERROR_CIRCULAR_DEPENDENCY,
        ERROR_SERVICE_DOES_NOT_EXIST,
        ERROR_SERVICE_CANNOT_ACCEPT_CTRL,
        ERROR_SERVICE_NOT_ACTIVE,
        ERROR_FAILED_SERVICE_CONTROLLER_CONNECT,
        ERROR_EXCEPTION_IN_SERVICE,
        ERROR_DATABASE_DOES_NOT_EXIST,
        ERROR_SERVICE_SPECIFIC_ERROR,
        ERROR_PROCESS_ABORTED,
        ERROR_SERVICE_DEPENDENCY_FAIL,
        ERROR_SERVICE_LOGON_FAILED,
        ERROR_SERVICE_START_HANG,
        ERROR_INVALID_SERVICE_LOCK,
        ERROR_SERVICE_MARKED_FOR_DELETE,
        ERROR_SERVICE_EXISTS,
        ERROR_ALREADY_RUNNING_LKG,
        ERROR_SERVICE_DEPENDENCY_DELETED,
        ERROR_BOOT_ALREADY_ACCEPTED,
        ERROR_SERVICE_NEVER_STARTED,
        ERROR_DUPLICATE_SERVICE_NAME,
        ERROR_DIFFERENT_SERVICE_ACCOUNT,
        ERROR_CANNOT_DETECT_DRIVER_FAILURE,
        ERROR_CANNOT_DETECT_PROCESS_ABORT,
        ERROR_NO_RECOVERY_PROGRAM,
        ERROR_END_OF_MEDIA,
        ERROR_FILEMARK_DETECTED,
        ERROR_BEGINNING_OF_MEDIA,
        ERROR_SETMARK_DETECTED,
        ERROR_NO_DATA_DETECTED,
        ERROR_PARTITION_FAILURE,
        ERROR_INVALID_BLOCK_LENGTH,
        ERROR_DEVICE_NOT_PARTITIONED,
        ERROR_UNABLE_TO_LOCK_MEDIA,
        ERROR_UNABLE_TO_UNLOAD_MEDIA,
        ERROR_MEDIA_CHANGED,
        ERROR_BUS_RESET,
        ERROR_NO_MEDIA_IN_DRIVE,
        ERROR_NO_UNICODE_TRANSLATION,
        ERROR_DLL_INIT_FAILED,
        ERROR_SHUTDOWN_IN_PROGRESS,
        ERROR_NO_SHUTDOWN_IN_PROGRESS,
        ERROR_IO_DEVICE,
        ERROR_SERIAL_NO_DEVICE,
        ERROR_IRQ_BUSY,
        ERROR_MORE_WRITES,
        ERROR_COUNTER_TIMEOUT,
        ERROR_FLOPPY_ID_MARK_NOT_FOUND,
        ERROR_FLOPPY_WRONG_CYLINDER,
        ERROR_FLOPPY_UNKNOWN_ERROR,
        ERROR_FLOPPY_BAD_REGISTERS,
        ERROR_DISK_RECALIBRATE_FAILED,
        ERROR_DISK_OPERATION_FAILED,
        ERROR_DISK_RESET_FAILED,
        ERROR_EOM_OVERFLOW,
        ERROR_NOT_ENOUGH_SERVER_MEMORY,
        ERROR_POSSIBLE_DEADLOCK,
        ERROR_MAPPED_ALIGNMENT,
        ERROR_SET_POWER_STATE_VETOED,
        ERROR_SET_POWER_STATE_FAILED,
        ERROR_TOO_MANY_LINKS,
        ERROR_OLD_WIN_VERSION,
        ERROR_APP_WRONG_OS,
        ERROR_SINGLE_INSTANCE_APP,
        ERROR_RMODE_APP,
        ERROR_INVALID_DLL,
        ERROR_NO_ASSOCIATION,
        ERROR_DDE_FAIL,
        ERROR_DLL_NOT_FOUND,
        ERROR_NO_MORE_USER_HANDLES,
        ERROR_MESSAGE_SYNC_ONLY,
        ERROR_SOURCE_ELEMENT_EMPTY,
        ERROR_DESTINATION_ELEMENT_FULL,
        ERROR_ILLEGAL_ELEMENT_ADDRESS,
        ERROR_MAGAZINE_NOT_PRESENT,
        ERROR_DEVICE_REINITIALIZATION_NEEDED,
        ERROR_DEVICE_REQUIRES_CLEANING,
        ERROR_DEVICE_DOOR_OPEN,
        ERROR_DEVICE_NOT_CONNECTED,
        ERROR_NOT_FOUND,
        ERROR_NO_MATCH,
        ERROR_SET_NOT_FOUND,
        ERROR_POINT_NOT_FOUND,
        ERROR_NO_TRACKING_SERVICE,
        ERROR_NO_VOLUME_ID,
        ERROR_CONNECTED_OTHER_PASSWORD,
        ERROR_BAD_USERNAME,
        ERROR_NOT_CONNECTED,
        ERROR_OPEN_FILES,
        ERROR_ACTIVE_CONNECTIONS,
        ERROR_DEVICE_IN_USE,
        ERROR_BAD_DEVICE,
        ERROR_CONNECTION_UNAVAIL,
        ERROR_DEVICE_ALREADY_REMEMBERED,
        ERROR_NO_NET_OR_BAD_PATH,
        ERROR_BAD_PROVIDER,
        ERROR_CANNOT_OPEN_PROFILE,
        ERROR_BAD_PROFILE,
        ERROR_NOT_CONTAINER,
        ERROR_EXTENDED_ERROR,
        ERROR_INVALID_GROUPNAME,
        ERROR_INVALID_COMPUTERNAME,
        ERROR_INVALID_EVENTNAME,
        ERROR_INVALID_DOMAINNAME,
        ERROR_INVALID_SERVICENAME,
        ERROR_INVALID_NETNAME,
        ERROR_INVALID_SHARENAME,
        ERROR_INVALID_PASSWORDNAME,
        ERROR_INVALID_MESSAGENAME,
        ERROR_INVALID_MESSAGEDEST,
        ERROR_SESSION_CREDENTIAL_CONFLICT,
        ERROR_REMOTE_SESSION_LIMIT_EXCEEDED,
        ERROR_DUP_DOMAINNAME,
        ERROR_NO_NETWORK,
        ERROR_CANCELLED,
        ERROR_USER_MAPPED_FILE,
        ERROR_CONNECTION_REFUSED,
        ERROR_GRACEFUL_DISCONNECT,
        ERROR_ADDRESS_ALREADY_ASSOCIATED,
        ERROR_ADDRESS_NOT_ASSOCIATED,
        ERROR_CONNECTION_INVALID,
        ERROR_CONNECTION_ACTIVE,
        ERROR_NETWORK_UNREACHABLE,
        ERROR_HOST_UNREACHABLE,
        ERROR_PROTOCOL_UNREACHABLE,
        ERROR_PORT_UNREACHABLE,
        ERROR_REQUEST_ABORTED,
        ERROR_CONNECTION_ABORTED,
        ERROR_RETRY,
        ERROR_CONNECTION_COUNT_LIMIT,
        ERROR_LOGIN_TIME_RESTRICTION,
        ERROR_LOGIN_WKSTA_RESTRICTION,
        ERROR_INCORRECT_ADDRESS,
        ERROR_ALREADY_REGISTERED,
        ERROR_SERVICE_NOT_FOUND,
        ERROR_NOT_AUTHENTICATED,
        ERROR_NOT_LOGGED_ON,
        ERROR_CONTINUE,
        ERROR_ALREADY_INITIALIZED,
        ERROR_NO_MORE_DEVICES,
        ERROR_NO_SUCH_SITE,
        ERROR_DOMAIN_CONTROLLER_EXISTS,
        ERROR_DS_NOT_INSTALLED,
        ERROR_NOT_ALL_ASSIGNED,
        ERROR_SOME_NOT_MAPPED,
        ERROR_NO_QUOTAS_FOR_ACCOUNT,
        ERROR_LOCAL_USER_SESSION_KEY,
        ERROR_NULL_LM_PASSWORD,
        ERROR_UNKNOWN_REVISION,
        ERROR_REVISION_MISMATCH,
        ERROR_INVALID_OWNER,
        ERROR_INVALID_PRIMARY_GROUP,
        ERROR_NO_IMPERSONATION_TOKEN,
        ERROR_CANT_DISABLE_MANDATORY,
        ERROR_NO_LOGON_SERVERS,
        ERROR_NO_SUCH_LOGON_SESSION,
        ERROR_NO_SUCH_PRIVILEGE,
        ERROR_PRIVILEGE_NOT_HELD,
        ERROR_INVALID_ACCOUNT_NAME,
        ERROR_USER_EXISTS,
        ERROR_NO_SUCH_USER,
        ERROR_GROUP_EXISTS,
        ERROR_NO_SUCH_GROUP,
        ERROR_MEMBER_IN_GROUP,
        ERROR_MEMBER_NOT_IN_GROUP,
        ERROR_LAST_ADMIN,
        ERROR_WRONG_PASSWORD,
        ERROR_ILL_FORMED_PASSWORD,
        ERROR_PASSWORD_RESTRICTION,
        ERROR_LOGON_FAILURE,
        ERROR_ACCOUNT_RESTRICTION,
        ERROR_INVALID_LOGON_HOURS,
        ERROR_INVALID_WORKSTATION,
        ERROR_PASSWORD_EXPIRED,
        ERROR_ACCOUNT_DISABLED,
        ERROR_NONE_MAPPED,
        ERROR_TOO_MANY_LUIDS_REQUESTED,
        ERROR_LUIDS_EXHAUSTED,
        ERROR_INVALID_SUB_AUTHORITY,
        ERROR_INVALID_ACL,
        ERROR_INVALID_SID,
        ERROR_INVALID_SECURITY_DESCR,
        ERROR_BAD_INHERITANCE_ACL,
        ERROR_SERVER_DISABLED,
        ERROR_SERVER_NOT_DISABLED,
        ERROR_INVALID_ID_AUTHORITY,
        ERROR_ALLOTTED_SPACE_EXCEEDED,
        ERROR_INVALID_GROUP_ATTRIBUTES,
        ERROR_BAD_IMPERSONATION_LEVEL,
        ERROR_CANT_OPEN_ANONYMOUS,
        ERROR_BAD_VALIDATION_CLASS,
        ERROR_BAD_TOKEN_TYPE,
        ERROR_NO_SECURITY_ON_OBJECT,
        ERROR_CANT_ACCESS_DOMAIN_INFO,
        ERROR_INVALID_SERVER_STATE,
        ERROR_INVALID_DOMAIN_STATE,
        ERROR_INVALID_DOMAIN_ROLE,
        ERROR_NO_SUCH_DOMAIN,
        ERROR_DOMAIN_EXISTS,
        ERROR_DOMAIN_LIMIT_EXCEEDED,
        ERROR_INTERNAL_DB_CORRUPTION,
        ERROR_INTERNAL_ERROR,
        ERROR_GENERIC_NOT_MAPPED,
        ERROR_BAD_DESCRIPTOR_FORMAT,
        ERROR_NOT_LOGON_PROCESS,
        ERROR_LOGON_SESSION_EXISTS,
        ERROR_NO_SUCH_PACKAGE,
        ERROR_BAD_LOGON_SESSION_STATE,
        ERROR_LOGON_SESSION_COLLISION,
        ERROR_INVALID_LOGON_TYPE,
        ERROR_CANNOT_IMPERSONATE,
        ERROR_RXACT_INVALID_STATE,
        ERROR_RXACT_COMMIT_FAILURE,
        ERROR_SPECIAL_ACCOUNT,
        ERROR_SPECIAL_GROUP,
        ERROR_SPECIAL_USER,
        ERROR_MEMBERS_PRIMARY_GROUP,
        ERROR_TOKEN_ALREADY_IN_USE,
        ERROR_NO_SUCH_ALIAS,
        ERROR_MEMBER_NOT_IN_ALIAS,
        ERROR_MEMBER_IN_ALIAS,
        ERROR_ALIAS_EXISTS,
        ERROR_LOGON_NOT_GRANTED,
        ERROR_TOO_MANY_SECRETS,
        ERROR_SECRET_TOO_LONG,
        ERROR_INTERNAL_DB_ERROR,
        ERROR_TOO_MANY_CONTEXT_IDS,
        ERROR_LOGON_TYPE_NOT_GRANTED,
        ERROR_NT_CROSS_ENCRYPTION_REQUIRED,
        ERROR_NO_SUCH_MEMBER,
        ERROR_INVALID_MEMBER,
        ERROR_TOO_MANY_SIDS,
        ERROR_LM_CROSS_ENCRYPTION_REQUIRED,
        ERROR_NO_INHERITANCE,
        ERROR_FILE_CORRUPT,
        ERROR_DISK_CORRUPT,
        ERROR_NO_USER_SESSION_KEY,
        ERROR_LICENSE_QUOTA_EXCEEDED,
        ERROR_INVALID_WINDOW_HANDLE,
        ERROR_INVALID_MENU_HANDLE,
        ERROR_INVALID_CURSOR_HANDLE,
        ERROR_INVALID_ACCEL_HANDLE,
        ERROR_INVALID_HOOK_HANDLE,
        ERROR_INVALID_DWP_HANDLE,
        ERROR_TLW_WITH_WSCHILD,
        ERROR_CANNOT_FIND_WND_CLASS,
        ERROR_WINDOW_OF_OTHER_THREAD,
        ERROR_HOTKEY_ALREADY_REGISTERED,
        ERROR_CLASS_ALREADY_EXISTS,
        ERROR_CLASS_DOES_NOT_EXIST,
        ERROR_CLASS_HAS_WINDOWS,
        ERROR_INVALID_INDEX,
        ERROR_INVALID_ICON_HANDLE,
        ERROR_PRIVATE_DIALOG_INDEX,
        ERROR_LISTBOX_ID_NOT_FOUND,
        ERROR_NO_WILDCARD_CHARACTERS,
        ERROR_CLIPBOARD_NOT_OPEN,
        ERROR_HOTKEY_NOT_REGISTERED,
        ERROR_WINDOW_NOT_DIALOG,
        ERROR_CONTROL_ID_NOT_FOUND,
        ERROR_INVALID_COMBOBOX_MESSAGE,
        ERROR_WINDOW_NOT_COMBOBOX,
        ERROR_INVALID_EDIT_HEIGHT,
        ERROR_DC_NOT_FOUND,
        ERROR_INVALID_HOOK_FILTER,
        ERROR_INVALID_FILTER_PROC,
        ERROR_HOOK_NEEDS_HMOD,
        ERROR_GLOBAL_ONLY_HOOK,
        ERROR_JOURNAL_HOOK_SET,
        ERROR_HOOK_NOT_INSTALLED,
        ERROR_INVALID_LB_MESSAGE,
        ERROR_SETCOUNT_ON_BAD_LB,
        ERROR_LB_WITHOUT_TABSTOPS,
        ERROR_DESTROY_OBJECT_OF_OTHER_THREAD,
        ERROR_CHILD_WINDOW_MENU,
        ERROR_NO_SYSTEM_MENU,
        ERROR_INVALID_MSGBOX_STYLE,
        ERROR_INVALID_SPI_VALUE,
        ERROR_SCREEN_ALREADY_LOCKED,
        ERROR_HWNDS_HAVE_DIFF_PARENT,
        ERROR_NOT_CHILD_WINDOW,
        ERROR_INVALID_GW_COMMAND,
        ERROR_INVALID_THREAD_ID,
        ERROR_NON_MDICHILD_WINDOW,
        ERROR_POPUP_ALREADY_ACTIVE,
        ERROR_NO_SCROLLBARS,
        ERROR_INVALID_SCROLLBAR_RANGE,
        ERROR_INVALID_SHOWWIN_COMMAND,
        ERROR_NO_SYSTEM_RESOURCES,
        ERROR_NONPAGED_SYSTEM_RESOURCES,
        ERROR_PAGED_SYSTEM_RESOURCES,
        ERROR_WORKING_SET_QUOTA,
        ERROR_PAGEFILE_QUOTA,
        ERROR_COMMITMENT_LIMIT,
        ERROR_MENU_ITEM_NOT_FOUND,
        ERROR_INVALID_KEYBOARD_HANDLE,
        ERROR_HOOK_TYPE_NOT_ALLOWED,
        ERROR_REQUIRES_INTERACTIVE_WINDOWSTATION,
        ERROR_TIMEOUT,
        ERROR_INVALID_MONITOR_HANDLE,
        ERROR_EVENTLOG_FILE_CORRUPT,
        ERROR_EVENTLOG_CANT_START,
        ERROR_LOG_FILE_FULL,
        ERROR_EVENTLOG_FILE_CHANGED,
#ifdef ERROR_INSTALL_SERVICE
        ERROR_INSTALL_SERVICE,
#endif
        ERROR_INSTALL_USEREXIT,
        ERROR_INSTALL_FAILURE,
        ERROR_INSTALL_SUSPEND,
        ERROR_UNKNOWN_PRODUCT,
        ERROR_UNKNOWN_FEATURE,
        ERROR_UNKNOWN_COMPONENT,
        ERROR_UNKNOWN_PROPERTY,
        ERROR_INVALID_HANDLE_STATE,
        ERROR_BAD_CONFIGURATION,
        ERROR_INDEX_ABSENT,
        ERROR_INSTALL_SOURCE_ABSENT,
#ifdef ERROR_BAD_DATABASE_VERSION
        ERROR_BAD_DATABASE_VERSION,
#endif
        ERROR_PRODUCT_UNINSTALLED,
        ERROR_BAD_QUERY_SYNTAX,
        ERROR_INVALID_FIELD,
        ERROR_INVALID_USER_BUFFER,
        ERROR_UNRECOGNIZED_MEDIA,
        ERROR_NO_TRUST_LSA_SECRET,
        ERROR_NO_TRUST_SAM_ACCOUNT,
        ERROR_TRUSTED_DOMAIN_FAILURE,
        ERROR_TRUSTED_RELATIONSHIP_FAILURE,
        ERROR_TRUST_FAILURE,
        ERROR_NETLOGON_NOT_STARTED,
        ERROR_ACCOUNT_EXPIRED,
        ERROR_REDIRECTOR_HAS_OPEN_HANDLES,
        ERROR_PRINTER_DRIVER_ALREADY_INSTALLED,
        ERROR_UNKNOWN_PORT,
        ERROR_UNKNOWN_PRINTER_DRIVER,
        ERROR_UNKNOWN_PRINTPROCESSOR,
        ERROR_INVALID_SEPARATOR_FILE,
        ERROR_INVALID_PRIORITY,
        ERROR_INVALID_PRINTER_NAME,
        ERROR_PRINTER_ALREADY_EXISTS,
        ERROR_INVALID_PRINTER_COMMAND,
        ERROR_INVALID_DATATYPE,
        ERROR_INVALID_ENVIRONMENT,
        ERROR_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT,
        ERROR_NOLOGON_WORKSTATION_TRUST_ACCOUNT,
        ERROR_NOLOGON_SERVER_TRUST_ACCOUNT,
        ERROR_DOMAIN_TRUST_INCONSISTENT,
        ERROR_SERVER_HAS_OPEN_HANDLES,
        ERROR_RESOURCE_DATA_NOT_FOUND,
        ERROR_RESOURCE_TYPE_NOT_FOUND,
        ERROR_RESOURCE_NAME_NOT_FOUND,
        ERROR_RESOURCE_LANG_NOT_FOUND,
        ERROR_NOT_ENOUGH_QUOTA,
        ERROR_INVALID_TIME,
        ERROR_INVALID_FORM_NAME,
        ERROR_INVALID_FORM_SIZE,
        ERROR_ALREADY_WAITING,
        ERROR_PRINTER_DELETED,
        ERROR_INVALID_PRINTER_STATE,
        ERROR_PASSWORD_MUST_CHANGE,
        ERROR_DOMAIN_CONTROLLER_NOT_FOUND,
        ERROR_ACCOUNT_LOCKED_OUT,
        ERROR_NO_SITENAME,
        ERROR_CANT_ACCESS_FILE,
        ERROR_CANT_RESOLVE_FILENAME,
        ERROR_DS_MEMBERSHIP_EVALUATED_LOCALLY,
        ERROR_DS_NO_ATTRIBUTE_OR_VALUE,
        ERROR_DS_INVALID_ATTRIBUTE_SYNTAX,
        ERROR_DS_ATTRIBUTE_TYPE_UNDEFINED,
        ERROR_DS_ATTRIBUTE_OR_VALUE_EXISTS,
        ERROR_DS_BUSY,
        ERROR_DS_UNAVAILABLE,
        ERROR_DS_NO_RIDS_ALLOCATED,
        ERROR_DS_NO_MORE_RIDS,
        ERROR_DS_INCORRECT_ROLE_OWNER,
        ERROR_DS_RIDMGR_INIT_ERROR,
        ERROR_DS_OBJ_CLASS_VIOLATION,
        ERROR_DS_CANT_ON_NON_LEAF,
        ERROR_DS_CANT_ON_RDN,
        ERROR_DS_CANT_MOD_OBJ_CLASS,
        ERROR_DS_CROSS_DOM_MOVE_ERROR,
        ERROR_DS_GC_NOT_AVAILABLE,
        ERROR_NO_BROWSER_SERVERS_FOUND,
        ERROR_INVALID_PIXEL_FORMAT,
        ERROR_BAD_DRIVER,
        ERROR_INVALID_WINDOW_STYLE,
        ERROR_METAFILE_NOT_SUPPORTED,
        ERROR_TRANSFORM_NOT_SUPPORTED,
        ERROR_CLIPPING_NOT_SUPPORTED,
        ERROR_INVALID_CMM,
        ERROR_INVALID_PROFILE,
        ERROR_TAG_NOT_FOUND,
        ERROR_TAG_NOT_PRESENT,
        ERROR_DUPLICATE_TAG,
        ERROR_PROFILE_NOT_ASSOCIATED_WITH_DEVICE,
        ERROR_PROFILE_NOT_FOUND,
        ERROR_INVALID_COLORSPACE,
        ERROR_ICM_NOT_ENABLED,
        ERROR_DELETING_ICM_XFORM,
        ERROR_INVALID_TRANSFORM,
        ERROR_UNKNOWN_PRINT_MONITOR,
        ERROR_PRINTER_DRIVER_IN_USE,
        ERROR_SPOOL_FILE_NOT_FOUND,
        ERROR_SPL_NO_STARTDOC,
        ERROR_SPL_NO_ADDJOB,
        ERROR_PRINT_PROCESSOR_ALREADY_INSTALLED,
        ERROR_PRINT_MONITOR_ALREADY_INSTALLED,
        ERROR_INVALID_PRINT_MONITOR,
        ERROR_PRINT_MONITOR_IN_USE,
        ERROR_PRINTER_HAS_JOBS_QUEUED,
        ERROR_SUCCESS_REBOOT_REQUIRED,
        ERROR_SUCCESS_RESTART_REQUIRED,
        ERROR_WINS_INTERNAL,
        ERROR_CAN_NOT_DEL_LOCAL_WINS,
        ERROR_STATIC_INIT,
        ERROR_INC_BACKUP,
        ERROR_FULL_BACKUP,
        ERROR_REC_NON_EXISTENT,
        ERROR_RPL_NOT_ALLOWED,
        ERROR_DHCP_ADDRESS_CONFLICT,
        ERROR_WMI_GUID_NOT_FOUND,
        ERROR_WMI_INSTANCE_NOT_FOUND,
        ERROR_WMI_ITEMID_NOT_FOUND,
        ERROR_WMI_TRY_AGAIN,
        ERROR_WMI_DP_NOT_FOUND,
        ERROR_WMI_UNRESOLVED_INSTANCE_REF,
        ERROR_WMI_ALREADY_ENABLED,
        ERROR_WMI_GUID_DISCONNECTED,
        ERROR_WMI_SERVER_UNAVAILABLE,
        ERROR_WMI_DP_FAILED,
        ERROR_WMI_INVALID_MOF,
        ERROR_WMI_INVALID_REGINFO,
        ERROR_INVALID_MEDIA,
        ERROR_INVALID_LIBRARY,
        ERROR_INVALID_MEDIA_POOL,
        ERROR_DRIVE_MEDIA_MISMATCH,
        ERROR_MEDIA_OFFLINE,
        ERROR_LIBRARY_OFFLINE,
        ERROR_EMPTY,
        ERROR_NOT_EMPTY,
        ERROR_MEDIA_UNAVAILABLE,
        ERROR_RESOURCE_DISABLED,
        ERROR_INVALID_CLEANER,
        ERROR_UNABLE_TO_CLEAN,
        ERROR_OBJECT_NOT_FOUND,
        ERROR_DATABASE_FAILURE,
        ERROR_DATABASE_FULL,
        ERROR_MEDIA_INCOMPATIBLE,
        ERROR_RESOURCE_NOT_PRESENT,
        ERROR_INVALID_OPERATION,
        ERROR_MEDIA_NOT_AVAILABLE,
        ERROR_DEVICE_NOT_AVAILABLE,
        ERROR_REQUEST_REFUSED,
        ERROR_FILE_OFFLINE,
        ERROR_REMOTE_STORAGE_NOT_ACTIVE,
        ERROR_REMOTE_STORAGE_MEDIA_ERROR,
        ERROR_NOT_A_REPARSE_POINT,
        ERROR_REPARSE_ATTRIBUTE_CONFLICT,
        ERROR_DEPENDENT_RESOURCE_EXISTS,
        ERROR_DEPENDENCY_NOT_FOUND,
        ERROR_DEPENDENCY_ALREADY_EXISTS,
        ERROR_RESOURCE_NOT_ONLINE,
        ERROR_HOST_NODE_NOT_AVAILABLE,
        ERROR_RESOURCE_NOT_AVAILABLE,
        ERROR_RESOURCE_NOT_FOUND,
        ERROR_SHUTDOWN_CLUSTER,
        ERROR_CANT_EVICT_ACTIVE_NODE,
        ERROR_OBJECT_ALREADY_EXISTS,
        ERROR_OBJECT_IN_LIST,
        ERROR_GROUP_NOT_AVAILABLE,
        ERROR_GROUP_NOT_FOUND,
        ERROR_GROUP_NOT_ONLINE,
        ERROR_HOST_NODE_NOT_RESOURCE_OWNER,
        ERROR_HOST_NODE_NOT_GROUP_OWNER,
        ERROR_RESMON_CREATE_FAILED,
        ERROR_RESMON_ONLINE_FAILED,
        ERROR_RESOURCE_ONLINE,
        ERROR_QUORUM_RESOURCE,
        ERROR_NOT_QUORUM_CAPABLE,
        ERROR_CLUSTER_SHUTTING_DOWN,
        ERROR_INVALID_STATE,
        ERROR_RESOURCE_PROPERTIES_STORED,
        ERROR_NOT_QUORUM_CLASS,
        ERROR_CORE_RESOURCE,
        ERROR_QUORUM_RESOURCE_ONLINE_FAILED,
        ERROR_QUORUMLOG_OPEN_FAILED,
        ERROR_CLUSTERLOG_CORRUPT,
        ERROR_CLUSTERLOG_RECORD_EXCEEDS_MAXSIZE,
        ERROR_CLUSTERLOG_EXCEEDS_MAXSIZE,
        ERROR_CLUSTERLOG_CHKPOINT_NOT_FOUND,
        ERROR_CLUSTERLOG_NOT_ENOUGH_SPACE,
        ERROR_ENCRYPTION_FAILED,
        ERROR_DECRYPTION_FAILED,
        ERROR_FILE_ENCRYPTED,
        ERROR_NO_RECOVERY_POLICY,
        ERROR_NO_EFS,
        ERROR_WRONG_EFS,
        ERROR_NO_USER_KEYS,
        ERROR_FILE_NOT_ENCRYPTED,
        ERROR_NOT_EXPORT_FORMAT,
    };

    static DWORD code_only_inserts[] = 
    {
        ERROR_WRONG_DISK,
        ERROR_SEM_USER_LIMIT,
        ERROR_CHILD_NOT_COMPLETE,
        ERROR_INVALID_ORDINAL,
        ERROR_INVALID_STARTING_CODESEG,
        ERROR_INVALID_STACKSEG,
        ERROR_INVALID_MODULETYPE,
        ERROR_INVALID_EXE_SIGNATURE,
        ERROR_EXE_MARKED_INVALID,
        ERROR_BAD_EXE_FORMAT,
        ERROR_ITERATED_DATA_EXCEEDS_64k,
        ERROR_INVALID_MINALLOCSIZE,
        ERROR_INVALID_SEGDPL,
        ERROR_RELOC_CHAIN_XEEDS_SEGLIM,
        ERROR_INFLOOP_IN_RELOC_CHAIN,
        ERROR_EXE_MACHINE_TYPE_MISMATCH,
        ERROR_MR_MID_NOT_FOUND,
    };


	using ::winstl::ws_char_a_t;
	using ::winstl::winstl_C_format_message_strerror_a;
	using ::winstl::winstl_C_format_message_free_buff_a;
	using ::winstl::ws_char_w_t;
//	using ::winstl::winstl_C_format_message_strerror_w;
	using ::winstl::winstl_C_format_message_free_buff_w;

static void test_winstl_C_format_message_strerror_a()
{
	// no inserts
    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(code_no_inserts); ++i)
    {
        LONG const e = stlsoft_static_cast(LONG, code_no_inserts[i]);

		ws_char_a_t* ed = winstl_C_format_message_strerror_a(e);

		if(NULL == ed)
		{
			switch(::GetLastError())
			{
				case	ERROR_OUTOFMEMORY:
//					XTESTS_WARNING("out of memory");
				case	ERROR_MR_MID_NOT_FOUND:
					// benign failure
					break;
				default:
					XTESTS_TEST_FAIL("");
					break;
			}
		}
		else
		{
			stlsoft::scoped_handle<CHAR*>	scoper(ed, winstl_C_format_message_free_buff_a);

	        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(lookup_error_or_number_a(e), ed);
		}
    }}

	// inserts
    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(code_only_inserts); ++i)
    {
        LONG const e = stlsoft_static_cast(LONG, code_only_inserts[i]);

		ws_char_a_t* ed = winstl_C_format_message_strerror_a(e);

		if(NULL == ed)
		{
			switch(::GetLastError())
			{
				case	ERROR_OUTOFMEMORY:
//					XTESTS_WARNING("out of memory");
				case	ERROR_MR_MID_NOT_FOUND:
					// benign failure
					break;
				default:
					XTESTS_TEST_FAIL("");
					break;
			}
		}
		else
		{
			stlsoft::scoped_handle<CHAR*>	scoper(ed, winstl_C_format_message_free_buff_a);

	        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(lookup_error_or_number_a(e), ed);
		}
    }}
}

static void test_format_message_multibyte()
{
    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(code_no_inserts); ++i)
    {
        LONG const		e	=	stlsoft_static_cast(LONG, code_no_inserts[i]);
		ws_char_a_t*	ed;
		DWORD			n	=	winstl::format_message(0, NULL, e, &ed);

		if(0 == n)
		{
			switch(::GetLastError())
			{
				case	ERROR_OUTOFMEMORY:
//					XTESTS_WARNING("out of memory");
				case	ERROR_MR_MID_NOT_FOUND:
					// benign failure
					break;
				default:
					XTESTS_TEST_FAIL("");
					break;
			}
		}
		else
		{
			stlsoft::scoped_handle<CHAR*>	scoper(ed, winstl_C_format_message_free_buff_a);

			std::string	const				expected = lookup_error_a(e);

			XTESTS_TEST_INTEGER_EQUAL(expected.size(), n);
	        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(expected, ed);
		}
    }}
}

static void test_format_message_wide()
{
    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(code_no_inserts); ++i)
    {
        LONG const		e	=	stlsoft_static_cast(LONG, code_no_inserts[i]);
		ws_char_w_t*	ed;
		DWORD			n	=	winstl::format_message(0, NULL, e, &ed);

		if(0 == n)
		{
			switch(::GetLastError())
			{
				case	ERROR_OUTOFMEMORY:
//					XTESTS_WARNING("out of memory");
				case	ERROR_MR_MID_NOT_FOUND:
					// benign failure
					break;
				default:
					XTESTS_TEST_FAIL("");
					break;
			}
		}
		else
		{
			stlsoft::scoped_handle<WCHAR*>	scoper(ed, winstl_C_format_message_free_buff_w);

			std::wstring const				expected = lookup_error_w(e);

			XTESTS_TEST_INTEGER_EQUAL(expected.size(), n);
	        XTESTS_TEST_WIDE_STRING_EQUAL(expected, ed);
		}
    }}
}

} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
