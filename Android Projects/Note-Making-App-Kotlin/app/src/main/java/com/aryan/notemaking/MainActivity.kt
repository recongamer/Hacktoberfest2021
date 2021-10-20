package com.aryan.notemaking

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.Toast
import androidx.lifecycle.Observer
import androidx.lifecycle.ViewModelProvider
import androidx.recyclerview.widget.LinearLayoutManager
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity(), INotesRVAdapter {

    lateinit var viewModel: NoteViewModel
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        recy_view.layoutManager = LinearLayoutManager(this)
        val adapter = NotesRVadapter(this,this)
        recy_view.adapter = adapter

        viewModel = ViewModelProvider(this,ViewModelProvider.AndroidViewModelFactory.getInstance(application)).get(NoteViewModel::class.java)
        viewModel.allNotes.observe(this, Observer {list ->
            list?.let {
                adapter.updateList(it)
            }
        })
    }

    override fun onItemClicked(notes: Notes) {
        viewModel.deleteNode(notes)
        Toast.makeText(this,"${notes.text} Deleted",Toast.LENGTH_LONG).show()

    }

    fun submitData(view: View) {
        val noteText = et_notes.text.toString()
        if(noteText.isNotEmpty()){
            viewModel.insertNote(Notes(noteText))
            Toast.makeText(this,"${noteText} Inserted",Toast.LENGTH_LONG).show()
        }
    }
}