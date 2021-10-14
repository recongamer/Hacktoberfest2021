package com.aryan.notemaking

import android.content.Context
import android.media.Image
import android.text.Layout
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView

class NotesRVadapter(private val context: Context, private val listener: INotesRVAdapter): RecyclerView.Adapter<NotesRVadapter.NoteViewHolder>() {

    val allNotes = ArrayList<Notes>()
    inner class NoteViewHolder(itemView : View) : RecyclerView.ViewHolder(itemView){
        val textView = itemView.findViewById<TextView>(R.id.tv_text)
        val deleteButton = itemView.findViewById<ImageView>(R.id.iv_delete)

    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): NoteViewHolder {
      val viewHolder = NoteViewHolder(LayoutInflater.from(context).inflate(R.layout.item_note,parent,false))
        viewHolder.deleteButton.setOnClickListener {
            listener.onItemClicked(allNotes[viewHolder.adapterPosition])
        }

        return viewHolder
    }

    override fun onBindViewHolder(holder: NoteViewHolder, position: Int) {
        val currentNote = allNotes[position]
        holder.textView.text = currentNote.text
    }

    override fun getItemCount(): Int {
        return allNotes.size
    }

    fun updateList(newList : List<Notes>){
        allNotes.clear()
        allNotes.addAll(newList)
        notifyDataSetChanged()
    }
}

interface INotesRVAdapter {
    fun onItemClicked(notes: Notes)
}