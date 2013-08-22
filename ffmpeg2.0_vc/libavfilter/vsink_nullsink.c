/*
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include "avfilter.h"
#include "internal.h"
#include "libavutil/internal.h"

static int filter_frame(AVFilterLink *link, AVFrame *frame)
{
    av_frame_free(&frame);
    return 0;
}

static const AVFilterPad avfilter_vsink_nullsink_inputs[]={
	{
		/*.name=*/"default",
			/*.type=*/AVMEDIA_TYPE_VIDEO,
			/*.min_perms=*/0,
			/*.rej_perms=*/0,
			/*.start_frame=*/0,
			/*.get_video_buffer=*/0,
			/*.get_audio_buffer=*/0,
			/*.end_frame=*/0,
			/*.draw_slice=*/0,
			/*.filter_frame=*/filter_frame,
			/*.poll_frame=*/0,
			/*.request_frame=*/0,
			/*.config_props=*/0,
			/*.needs_fifo=*/0,
			/*.needs_writable=*/0,
	}
	,{NULL}};

	AVFilter avfilter_vsink_nullsink={
		/*.name=*/"nullsink",
		/*.description=*/NULL_IF_CONFIG_SMALL("Do absolutely nothing with the input video."),
		/*.inputs=*/avfilter_vsink_nullsink_inputs,
		/*.outputs=*/NULL,
		/*.priv_class=*/0,
		/*.flags=*/0,
		/*.init=*/0,
		/*.init_dict=*/0,
		/*.uninit=*/0,
		/*.query_formats=*/0,
		/*.priv_size=*/0,
		/*.next=*/0,
		/*.process_command=*/0,
		/*.init_opaque=*/0,
	};
