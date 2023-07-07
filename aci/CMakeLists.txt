if (CONFIG_INCLUDE_NET_CORE_IMAGE)
  add_child_image(
   NAME remote
   SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/../cpunet
   DOMAIN remote
   BOARD ${CONFIG_DOMAIN_CPUNET_BOARD}
  )
endif()