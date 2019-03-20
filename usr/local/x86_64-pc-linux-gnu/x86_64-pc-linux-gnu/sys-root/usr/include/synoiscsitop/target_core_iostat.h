#ifndef TARGET_CORE_IOSTAT_H
#define TARGET_CORE_IOSTAT_H
//This header is included by both user-space and kernel code.

typedef struct _tag_io_stat_report_t {
	uint64_t deferred_cmd_cnt;
	uint64_t ongoing_cmd_cnt;
	uint64_t queue_depth;

	uint64_t read_cmd_count;
	uint64_t read_bytes;
	uint64_t read_time_cost;
	uint64_t read_throughput;
	uint64_t read_avg_cmd_size;
	uint64_t read_avg_latency;
	uint64_t read_max_latency;
	uint64_t read_min_latency;

	uint64_t write_cmd_count;
	uint64_t write_bytes;
	uint64_t write_time_cost;
	uint64_t write_throughput;
	uint64_t write_avg_cmd_size;
	uint64_t write_avg_latency;
	uint64_t write_max_latency;
	uint64_t write_min_latency;

	uint64_t write_same_cmd_count;
	uint64_t unmap_cmd_count;
	uint64_t extended_copy_cmd_count;
	uint64_t extended_copy_optimized_rollback_cmd_count;
	uint64_t compare_and_write_cmd_count;

	uint64_t duration;
	uint64_t total_cmd_count;
	uint64_t total_io_latency;
	uint64_t total_avg_io_done_itvl;
	uint64_t total_avg_task_latency;
	uint64_t total_avg_task_itvl;
	uint64_t total_throughput;
	uint64_t total_iops;
	uint64_t net_cmd_count;

	uint64_t rx_idle_cost;
	uint64_t rx_avg_idle_latency;
	uint64_t rx_time_cost;;
	uint64_t rx_bytes;
	uint64_t rx_avg_size;
	uint64_t rx_avg_latency;
	uint64_t rx_throughput;

	uint64_t tx_idle_cost;
	uint64_t tx_avg_idle_latency;
	uint64_t tx_time_cost;
	uint64_t tx_bytes;
	uint64_t tx_avg_size;
	uint64_t tx_avg_latency;
	uint64_t tx_throughput;

	uint64_t task_itvl_usec;
	uint64_t rx_usec;
	uint64_t rx_idle_usec;
	uint64_t task_usec;
	uint64_t io_usec;
	uint64_t io_done_itvl_usec;
	uint64_t tx_idle_usec;
	uint64_t tx_usec;
} io_stat_report_t/*__attribute__((packed))*/;

#endif /* TARGET_CORE_IOSTAT_H */
