package com.aryan.notemaking

import android.app.Application
import androidx.lifecycle.AndroidViewModel
import androidx.lifecycle.LiveData
import androidx.lifecycle.viewModelScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch

class NoteViewModel(application: Application) : AndroidViewModel(application){

    private val dao = NoteRoomDatabase.getDatabase(application).getNoteDao()
    private val repo = NoteRepo(dao)
    val allNotes : LiveData<List<Notes>>

    init {
        val dao = NoteRoomDatabase.getDatabase(application).getNoteDao()
        val repo = NoteRepo(dao)
        allNotes = repo.allNotes
    }

    fun deleteNode(notes: Notes) = viewModelScope.launch(Dispatchers.IO) {
        repo.delete(notes)
    }

    fun insertNote(notes: Notes) = viewModelScope.launch(Dispatchers.IO) {
        repo.insert(notes)
    }

}