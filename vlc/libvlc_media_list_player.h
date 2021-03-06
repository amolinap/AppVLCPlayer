/*****************************************************************************
 * libvlc_media_list.h:  libvlc_media_list API
 *****************************************************************************
 * Copyright (C) 1998-2008 the VideoLAN team
 * $Id: libvlc_media_list_player.h 4 2010-12-27 10:44:22Z obooklage@gmail.com $
 *
 * Authors: Pierre d'Herbemont
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#ifndef LIBVLC_MEDIA_LIST_PLAYER_H
#define LIBVLC_MEDIA_LIST_PLAYER_H 1

/**
 * \file
 * This file defines libvlc_media_list_player API
 */

# ifdef __cplusplus
extern "C" {
# endif

/*****************************************************************************
 * Media List Player
 *****************************************************************************/
/** \defgroup libvlc_media_list_player LibVLC media list player
 * \ingroup libvlc
 * The LibVLC media list player plays a @ref libvlc_media_list_t list of media,
 * in a certain order.
 * This is required to especially support playlist files.
 * The normal @ref libvlc_media_player_t LibVLC media player can only play a
 * single media, and does not handle playlist files properly.
 * @{
 */

typedef struct libvlc_media_list_player_t libvlc_media_list_player_t;

/**
 *  Defines playback modes for playlist.
 */
typedef enum libvlc_playback_mode_t
{
    libvlc_playback_mode_default,
    libvlc_playback_mode_loop,
    libvlc_playback_mode_repeat
} libvlc_playback_mode_t;

/**
 * Create new media_list_player.
 *
 * \param p_instance libvlc instance
 * \return media list player instance or NULL on error
 */
VLC_PUBLIC_API libvlc_media_list_player_t *
    libvlc_media_list_player_new( libvlc_instance_t * p_instance );

/**
 * Release media_list_player.
 *
 * \param p_mlp media list player instance
 */
VLC_PUBLIC_API void
    libvlc_media_list_player_release( libvlc_media_list_player_t * p_mlp );

/**
 * Return the event manager of this media_list_player.
 *
 * \param p_mlp media list player instance
 * \return the event manager
 */
VLC_PUBLIC_API libvlc_event_manager_t *
    libvlc_media_list_player_event_manager(libvlc_media_list_player_t * p_mlp);

/**
 * Replace media player in media_list_player with this instance.
 *
 * \param p_mlp media list player instance
 * \param p_mi media player instance
 */
VLC_PUBLIC_API void
    libvlc_media_list_player_set_media_player(
                                     libvlc_media_list_player_t * p_mlp,
                                     libvlc_media_player_t * p_mi );

/**
 * Set the media list associated with the player
 *
 * \param p_mlp media list player instance
 * \param p_mlist list of media
 */
VLC_PUBLIC_API void
    libvlc_media_list_player_set_media_list(
                                     libvlc_media_list_player_t * p_mlp,
                                     libvlc_media_list_t * p_mlist );

/**
 * Play media list
 *
 * \param p_mlp media list player instance
 */
VLC_PUBLIC_API
void libvlc_media_list_player_play(libvlc_media_list_player_t * p_mlp);

/**
 * Pause media list
 *
 * \param p_mlp media list player instance
 */
VLC_PUBLIC_API
void libvlc_media_list_player_pause(libvlc_media_list_player_t * p_mlp);

/**
 * Is media list playing?
 *
 * \param p_mlp media list player instance
 * \return true for playing and false for not playing
 */
VLC_PUBLIC_API int
    libvlc_media_list_player_is_playing( libvlc_media_list_player_t * p_mlp );

/**
 * Get current libvlc_state of media list player
 *
 * \param p_mlp media list player instance
 * \return libvlc_state_t for media list player
 */
VLC_PUBLIC_API libvlc_state_t
    libvlc_media_list_player_get_state( libvlc_media_list_player_t * p_mlp );

/**
 * Play media list item at position index
 *
 * \param p_mlp media list player instance
 * \param i_index index in media list to play
 * \return 0 upon success -1 if the item wasn't found
 */
VLC_PUBLIC_API
int libvlc_media_list_player_play_item_at_index(libvlc_media_list_player_t * p_mlp,
                                                int i_index);

/**
 * Play the given media item
 *
 * \param p_mlp media list player instance
 * \param p_md the media instance
 * \return 0 upon success, -1 if the media is not part of the media list
 */
VLC_PUBLIC_API
int libvlc_media_list_player_play_item(libvlc_media_list_player_t * p_mlp,
                                       libvlc_media_t * p_md);

/**
 * Stop playing media list
 *
 * \param p_mlp media list player instance
 */
VLC_PUBLIC_API void
    libvlc_media_list_player_stop( libvlc_media_list_player_t * p_mlp);

/**
 * Play next item from media list
 *
 * \param p_mlp media list player instance
 * \return 0 upon success -1 if there is no next item
 */
VLC_PUBLIC_API
int libvlc_media_list_player_next(libvlc_media_list_player_t * p_mlp);

/**
 * Play previous item from media list
 *
 * \param p_mlp media list player instance
 * \return 0 upon success -1 if there is no previous item
 */
VLC_PUBLIC_API
int libvlc_media_list_player_previous(libvlc_media_list_player_t * p_mlp);



/**
 * Sets the playback mode for the playlist
 *
 * \param p_mlp media list player instance
 * \param e_mode playback mode specification
 */
VLC_PUBLIC_API
void libvlc_media_list_player_set_playback_mode(libvlc_media_list_player_t * p_mlp,
                                                libvlc_playback_mode_t e_mode );

/** @} media_list_player */

# ifdef __cplusplus
}
# endif

#endif /* LIBVLC_MEDIA_LIST_PLAYER_H */
