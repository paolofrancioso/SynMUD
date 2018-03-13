/**********************************************************************
 * SynMUD copyright (c) 2018 was created by                           *
 * Paolo 'Marduk' Francioso (email unknown)                           *
 **********************************************************************/ 

#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "mud.h"

void show_cyber( CHAR_DATA * ch ) {
	
   OBJ_DATA *obj;
   int iWear;
   bool found;
   
	//Cyberware Stuff
   set_char_color( AT_LBLUE, ch );
   send_to_char( "Your cyberware:\r\n", ch );
   set_char_color( AT_OBJECT, ch );
   
   //Template Block
   iWear = WEAR_CYBER_EYE;
   send_to_char( where_name[iWear], ch );
   
   found = FALSE;
   for( obj = ch->first_carrying; obj; obj = obj->next_content )
	  if( obj->wear_loc == iWear && obj->wear_loc == WEAR_CYBER_EYE )
	  {
	    send_to_char( format_obj_to_char( obj, ch, TRUE ), ch );
		found = TRUE;
	  }
	  
   if( !found )
      send_to_char( "Nothing.", ch );
     
   send_to_char( "\r\n", ch );
   //End of Template Block
   
   iWear = WEAR_CYBER_BRAIN;
   send_to_char( where_name[iWear], ch );
   
   found = FALSE;
   for( obj = ch->first_carrying; obj; obj = obj->next_content )
	  if( obj->wear_loc == iWear && obj->wear_loc == WEAR_CYBER_BRAIN )
	  {
	    send_to_char( format_obj_to_char( obj, ch, TRUE ), ch );
		found = TRUE;
	  }
	  
   if( !found )
      send_to_char( "Nothing.", ch );
     
   send_to_char( "\r\n", ch );

   iWear = WEAR_CYBER_ARMS;
   send_to_char( where_name[iWear], ch );
   
   found = FALSE;
   for( obj = ch->first_carrying; obj; obj = obj->next_content )
	  if( obj->wear_loc == iWear && obj->wear_loc == WEAR_CYBER_ARMS )
	  {
	    send_to_char( format_obj_to_char( obj, ch, TRUE ), ch );
		found = TRUE;
	  }
	  
   if( !found )
      send_to_char( "Nothing.", ch );
     
   send_to_char( "\r\n", ch );

   iWear = WEAR_CYBER_BODY;
   send_to_char( where_name[iWear], ch );
   
   found = FALSE;
   for( obj = ch->first_carrying; obj; obj = obj->next_content )
	  if( obj->wear_loc == iWear && obj->wear_loc == WEAR_CYBER_BODY )
	  {
	    send_to_char( format_obj_to_char( obj, ch, TRUE ), ch );
		found = TRUE;
	  }
	  
   if( !found )
      send_to_char( "Nothing.", ch );
     
   send_to_char( "\r\n", ch );

   iWear = WEAR_CYBER_LEGS;
   send_to_char( where_name[iWear], ch );
   
   found = FALSE;
   for( obj = ch->first_carrying; obj; obj = obj->next_content )
	  if( obj->wear_loc == iWear && obj->wear_loc == WEAR_CYBER_LEGS )
	  {
	    send_to_char( format_obj_to_char( obj, ch, TRUE ), ch );
		found = TRUE;
	  }
	  
   if( !found )
      send_to_char( "Nothing.", ch );
     
   send_to_char( "\r\n", ch );

   iWear = WEAR_CYBER_EPIDERMIS;
   send_to_char( where_name[iWear], ch );
   
   found = FALSE;
   for( obj = ch->first_carrying; obj; obj = obj->next_content )
	  if( obj->wear_loc == iWear && obj->wear_loc == WEAR_CYBER_EPIDERMIS )
	  {
	    send_to_char( format_obj_to_char( obj, ch, TRUE ), ch );
		found = TRUE;
	  }
	  
   if( !found )
      send_to_char( "Nothing.", ch );
     
   send_to_char( "\r\n", ch );   
		 
   return;
   
}

void wear_cyber( CHAR_DATA * ch, OBJ_DATA * obj, bool fReplace, short wear_bit )
{

   separate_obj( obj );

   if( obj->item_type == ITEM_CYBER_EYE )
   {
      equip_char( ch, obj, WEAR_CYBER_EYE );
      oprog_wear_trigger( ch, obj );
      return;
   }
   
   if( obj->item_type == ITEM_CYBER_BRAIN )
   {
      equip_char( ch, obj, WEAR_CYBER_BRAIN );
      oprog_wear_trigger( ch, obj );
      return;
   }
   
   if( obj->item_type == ITEM_CYBER_ARMS )
   {
      equip_char( ch, obj, WEAR_CYBER_ARMS );
      oprog_wear_trigger( ch, obj );
      return;
   }
   
   if( obj->item_type == ITEM_CYBER_LEGS )
   {
      equip_char( ch, obj, WEAR_CYBER_LEGS );
      oprog_wear_trigger( ch, obj );
      return;
   }
   
   if( obj->item_type == ITEM_CYBER_BODY )
   {
      equip_char( ch, obj, WEAR_CYBER_BODY );
      oprog_wear_trigger( ch, obj );
      return;
   }
  
   if( obj->item_type == ITEM_CYBER_EPIDERMIS )
   {
      equip_char( ch, obj, WEAR_CYBER_EPIDERMIS );
      oprog_wear_trigger( ch, obj );
      return;
   }  

}

//This is only for test purposes
void do_cyber( CHAR_DATA * ch, const char *argument )
{

   char arg1[MAX_INPUT_LENGTH];
   char arg2[MAX_INPUT_LENGTH];
   OBJ_DATA *obj;
   short wear_bit;

   argument = one_argument( argument, arg1 );
   argument = one_argument( argument, arg2 );
   if( ( !str_cmp( arg2, "on" ) || !str_cmp( arg2, "upon" ) || !str_cmp( arg2, "around" ) ) && argument[0] != '\0' )
      argument = one_argument( argument, arg2 );

   if( arg1[0] == '\0' )
   {
      send_to_char( "Which cyberware?\r\n", ch );
      return;
   }

   if( ms_find_obj( ch ) )
      return;

   if( !str_cmp( arg1, "all" ) )
   {
      OBJ_DATA *obj_next;

      for( obj = ch->first_carrying; obj; obj = obj_next )
      {
         obj_next = obj->next_content;
         if( obj->item_type == ITEM_BINDERS )
         {
            send_to_char( "You're into that S&&M stuff, eh?\r\n", ch );
            return;
         }
         if( obj->wear_loc == WEAR_NONE && can_see_obj( ch, obj ) )
            wear_cyber( ch, obj, FALSE, -1 );
      }
      return;
   }
   else
   {
      if( ( obj = get_obj_carry( ch, arg1 ) ) == NULL )
      {
         send_to_char( "You do not have that cyberware.\r\n", ch );
         return;
      }
      if( obj->item_type == ITEM_BINDERS )
      {
         send_to_char( "You're into that S&&M stuff, eh?\r\n", ch );
         return;
      }
      if( arg2[0] != '\0' )
         wear_bit = get_wflag( arg2 );
      else
         wear_bit = -1;
      wear_cyber( ch, obj, TRUE, wear_bit );
   }

   return;

}


void do_remove_cyber( CHAR_DATA * ch, const char *argument )
{

   OBJ_DATA *obj, *obj_next;
   char arg1[MAX_INPUT_LENGTH];
   char arg2[MAX_INPUT_LENGTH];
   CHAR_DATA *victim;

   if( IS_NPC( ch ) )
   {
      send_to_char( "Mob's can't mset\r\n", ch );
      return;
   }

   if( !ch->desc )
   {
      send_to_char( "You have no descriptor\r\n", ch );
      return;
   }

   victim = NULL;

	 argument = one_argument( argument, arg1 );
	 argument = one_argument( argument, arg2 );

   if( arg1[0] == '\0' || arg2[0] == '\0')
   {
     send_to_char( "Syntax: remcyber <victim> <object>\r\n", ch );
		 return;
   }
	 
	 if( !victim && get_trust( ch ) <= LEVEL_IMMORTAL )
   {
      if( ( victim = get_char_room( ch, arg1 ) ) == NULL )
      {
         send_to_char( "They aren't here.\r\n", ch );
         return;
      }
   }
   else if( !victim )
   {
      if( ( victim = get_char_world( ch, arg1 ) ) == NULL )
      {
         send_to_char( "No one like that in all the realms.\r\n", ch );
         return;
      }
   }

   if( !str_cmp( arg2, "all" ) )  /* SB Remove all */
   {
      for( obj = victim->first_carrying; obj != NULL; obj = obj_next )
      {
         obj_next = obj->next_content;
         if( obj->wear_loc != WEAR_NONE && can_see_obj( ch, obj ) && 
			       ( obj->item_type == ITEM_CYBER_EYE 
             || obj->item_type == ITEM_CYBER_BRAIN 
			       || obj->item_type == ITEM_CYBER_ARMS
             || obj->item_type == ITEM_CYBER_LEGS 
			       || obj->item_type == ITEM_CYBER_BODY
			       || obj->item_type == ITEM_CYBER_EPIDERMIS ) )
				 
            remove_obj( victim, obj->wear_loc, TRUE );
      }
      return;
   }

   if( ( obj = get_obj_wear( victim, arg2 ) ) == NULL )
   {
      send_to_char( "Item not found.\r\n", ch );
      return;
   }
   
   if( obj->item_type != ITEM_CYBER_EYE
		   && obj->item_type != ITEM_CYBER_BRAIN 
		   && obj->item_type != ITEM_CYBER_ARMS
			 && obj->item_type != ITEM_CYBER_LEGS 
		   && obj->item_type != ITEM_CYBER_BODY
			 && obj->item_type != ITEM_CYBER_EPIDERMIS )
   {
      send_to_char( "You can remove only cyberware with this command.\r\n", ch );
      return;
   }
   remove_obj( victim, obj->wear_loc, TRUE );
   return;
}